#include <iostream>
#include <thread>

class BankAccount {
 public:
  // 存款
  void Deposit(int amount) { balance_ += amount; }

  // 取款
  void Withdraw(int amount) { balance_ -= amount; }

  // 查询余额
  int GetBalance() { return balance_; }

 private:
  int balance_ = 0;
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