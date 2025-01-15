int tailRecursion(int n, int acc = 1) {
  if (n == 0) return acc;
  return tailRecursion(n - 1, n * acc);
}
