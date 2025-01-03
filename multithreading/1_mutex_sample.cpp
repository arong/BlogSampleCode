#include <iostream>
#include <mutex>
#include <thread>

class BankAccount {
 public:
  // 存款
  void Deposit(int amount) {
    std::lock_guard<std::mutex> lock(mutex_);
    balance_ += amount;
  }

  // 取款
  void Withdraw(int amount) {
    std::lock_guard<std::mutex> lock(mutex_);
    balance_ -= amount;
  }

  // 查询余额
  int GetBalance() {
    std::lock_guard<std::mutex> lock(mutex_);
    return balance_;
  }

 private:
  int balance_ = 0;
  std::mutex mutex_;
};

int main() {
  BankAccount account;

  std::thread t1([&account] { account.Deposit(100); });

  std::thread t2([&account] { account.Withdraw(100); });

  t1.join();
  t2.join();

  std::cout << "Balance: " << account.GetBalance() << std::endl;
  return 0;
}