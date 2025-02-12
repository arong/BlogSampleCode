import complex;
#include <iostream>

int main() {
  complex::Person joy(18, "Joy");
  std::cout << "Name: " << joy.Name() << "\n";
  std::cout << "Age : " << joy.Age() << "\n";
  return 0;
}
