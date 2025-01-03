#include <iostream>
#include <mutex>
#include <thread>

class BankAccount {
 public:
  // 存款
  void Deposit(int amount) {
    mutex.lock();
    balance_ += amount;
    mutex.unlock();
  }

  // 取款
  void Withdraw(int amount) {
    mutex.lock();
    balance_ -= amount;
    mutex.unlock();
  }

  // 查询余额
  int GetBalance() {
    int ret = 0;
    mutex.lock();
    ret = balance_;
    mutex.unlock();
    return ret;
  }

  void WithdrawTimeout(int amount) {
    if (mutex.try_lock_for(std::chrono::seconds(2))) {       // 尝试获取锁，超时时间为2秒
      std::this_thread::sleep_for(std::chrono::seconds(1));  // 模拟处理时间
      if (balance_ >= amount) {
        balance_ -= amount;
        std::cout << "Successfully withdrew: " << amount << ", Balance: " << balance_ << '\n';
      } else {
        std::cout << "Insufficient funds for withdrawal.\n";
      }
      mutex.unlock();
    } else {
      std::cout << "Failed to acquire lock for withdrawal within timeout.\n";
    }
  }

 private:
  int balance_ = 0;
  std::timed_mutex mutex;
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