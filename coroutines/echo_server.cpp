#include <arpa/inet.h>
#include <fcntl.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>

#include <coroutine>
#include <cstring>
#include <iostream>
#include <string>

// Helper function to make a socket non-blocking
void make_socket_non_blocking(int sockfd) {
  int flags = fcntl(sockfd, F_GETFL, 0);
  fcntl(sockfd, F_SETFL, flags | O_NONBLOCK);
}

// Coroutine promise and handle for asynchronous operations
struct Task {
  struct promise_type {
    auto get_return_object() { return Task{}; }
    auto initial_suspend() { return std::suspend_always{}; }
    auto final_suspend() noexcept { return std::suspend_always{}; }
    void return_void() {}
    void unhandled_exception() { std::terminate(); }
  };
};

// Awaitable read operation
struct ReadAwaitable {
  int sockfd;
  char* buffer;
  size_t length;

  bool await_ready() { return false; }
  void await_suspend(std::coroutine_handle<> handle) {
    while (true) {
      ssize_t n = recv(sockfd, buffer, length, 0);
      if (n > 0 || (n < 0 && errno != EAGAIN && errno != EWOULDBLOCK)) {
        handle.resume();
        return;
      }
    }
  }
  ssize_t await_resume() { return recv(sockfd, buffer, length, 0); }
};

// Awaitable write operation
struct WriteAwaitable {
  int sockfd;
  const char* buffer;
  size_t length;

  bool await_ready() { return false; }
  void await_suspend(std::coroutine_handle<> handle) {
    while (true) {
      ssize_t n = send(sockfd, buffer, length, 0);
      if (n >= 0 || (n < 0 && errno != EAGAIN && errno != EWOULDBLOCK)) {
        handle.resume();
        return;
      }
    }
  }
  ssize_t await_resume() { return send(sockfd, buffer, length, 0); }
};

// Echo session coroutine
Task echo_session(int client_sock) {
  char buffer[1024];
  while (true) {
    ssize_t n = co_await ReadAwaitable{client_sock, buffer, sizeof(buffer)};
    if (n <= 0) break;  // Connection closed or error
    co_await WriteAwaitable{client_sock, buffer, static_cast<size_t>(n)};
  }
  close(client_sock);
}

// Listener coroutine
Task listener(int server_sock) {
  while (true) {
    sockaddr_in client_addr{};
    socklen_t client_len = sizeof(client_addr);
    int client_sock = accept(server_sock, (sockaddr*)&client_addr, &client_len);
    if (client_sock >= 0) {
      make_socket_non_blocking(client_sock);
      echo_session(client_sock);
    }
  }
}

// Main function
int main() {
  int server_sock = socket(AF_INET, SOCK_STREAM, 0);
  if (server_sock < 0) {
    perror("Socket creation failed");
    return 1;
  }

  make_socket_non_blocking(server_sock);

  sockaddr_in server_addr{};
  server_addr.sin_family = AF_INET;
  server_addr.sin_addr.s_addr = INADDR_ANY;
  server_addr.sin_port = htons(12345);

  if (bind(server_sock, (sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
    perror("Bind failed");
    return 1;
  }

  if (listen(server_sock, 10) < 0) {
    perror("Listen failed");
    return 1;
  }

  std::cout << "Echo server is running on port 12345..." << std::endl;

  listener(server_sock);

  close(server_sock);
  return 0;
}
