constexpr int Sum(int N) { return (N == 0) ? 0 : N + Sum(N - 1); }

int main() { return Sum(3); }
