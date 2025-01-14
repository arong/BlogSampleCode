#include <iostream>
#include <string>

// candidate A
int lookUp(const std::string* key) { return 'A'; }

// candidate B
int lookUp(std::string* key) { return 'B'; }

int main() {
  std::string* str = new std::string("text");
  int value = lookUp(str);
  std::cout << value << std::endl;
}
