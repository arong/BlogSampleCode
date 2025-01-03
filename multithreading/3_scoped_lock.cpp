#include <iostream>
#include <mutex>
#include <shared_mutex>
#include <thread>

class BankAccount {
 public:
  // 存款
  void Deposit(int amount) {
    std::unique_lock<std::shared_mutex> lock(mutex_);
    balance_ += amount;
  }

  // 取款
  void Withdraw(int amount) {
    std::unique_lock<std::shared_mutex> lock(mutex_);
    balance_ -= amount;
  }

  // 查询余额
  int GetBalance() {
    std::shared_lock<std::shared_mutex> lock(mutex_);
    return balance_;
  }

  bool Transfer(BankAccount& to, int amount) {
    std::scoped_lock lock(mutex_, to.mutex_);

    if (balance_ >= amount) {
      balance_ -= amount;
      to.balance_ += amount;
      return true;
    }
    return false;
  }

 private:
  int balance_ = 0;
  std::shared_mutex mutex_;
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