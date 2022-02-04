unsigned Fibonacci(unsigned int n) {
  // f(0) = 0
  // f(1) = 1
  if (n == 1 || n == 0) {
    return n;
  } else {
    // f(n) = f(n-1) + f(n-2)
    return Fibonacci(n - 1) + Fibonacci(n - 2);
  }
}

unsigned FibonacciByIteration(unsigned int n) {
  // f(0) = 0
  // f(1) = 1
  if (n == 1 || n == 0) {
    return n;
  }

  // f(0) = 0
  unsigned int last = 0;
  // f(1) = 1
  unsigned int current = 1;
  // if n >= 2: f(n) = f(n-1) + f(n-2)
  for (int i = 0; i <= n - 2; ++i) {
    unsigned temp = current;
    current += last;
    last = temp;
  }
  return current;
}