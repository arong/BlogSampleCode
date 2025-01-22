#include <chrono>
#include <format>
#include <iostream>
#include <ratio>

int main() {
  std::chrono::system_clock::time_point tpoint{
      std::chrono::system_clock::now()};
  // Or:
  auto tpoint1{std::chrono::system_clock::now()};

  // Convert to a time_t.
  time_t tt{std::chrono::system_clock::to_time_t(tpoint)};
  // Convert to local time.
  tm* t{localtime(&tt)};
  // Write the time to the console.
  std::cout << std::put_time(t, "%H:%M:%S\n");
}
