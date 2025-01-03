struct POD {
  int a;
  int b;
  bool c;
};

int main() {
  int a = 0;
  int b = std::move(a);
  return 0;
}
