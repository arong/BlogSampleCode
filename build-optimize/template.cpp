template <int N>
struct Sum {
  static const int value = N + Sum<N - 1>::value;
};

template <>
struct Sum<0> {
  static const int value = 0;
};

int main() { return Sum<3>::value; }
