#include <cstring>
#include <iostream>

#include "stack2.hpp"

int main() {
  Stack<int, 20> arr;

  arr.Push(10);
  arr.Push(20);
  arr.Push(30);

  std::cout << "Stack size: " << arr.Size() << std::endl;
  std::cout << "Stack top: " << arr.Top() << std::endl;

  arr.Pop();
  std::cout << "After Pop, size: " << arr.Size() << std::endl;
  std::cout << "Stack top: " << arr.Top() << std::endl;

  Stack<bool, 20> stack;
  stack.Push(true);
  stack.Push(true);
  stack.Push(false);

  std::cout << "Stack size: " << stack.Size() << std::endl;
  std::cout << "Stack top: " << stack.Top() << std::endl;

  stack.Pop();
  std::cout << "After Pop, size: " << stack.Size() << std::endl;
  std::cout << "Stack top: " << stack.Top() << std::endl;

  Stack<char*, 30> strings;
  strings.Push(strdup("hello"));
  std::cout << "After Pop, size: " << strings.Size() << std::endl;
  std::cout << "Stack top: " << strings.Top() << std::endl;

  return 0;
}
