#include <iostream>

// overload J1
void fun(int &) { std::cout << "J1" << std::endl; }

// overload J2
void fun(...) { std::cout << "J2" << std::endl; }

struct MyStruct {
  int m_data : 5;  // bitfield, 5 bits stored in an int
};

int main() {
  MyStruct obj;
  fun(obj.m_data);  // 调用哪个?
}
