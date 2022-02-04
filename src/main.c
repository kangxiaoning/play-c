#include <stdio.h>

#include "algorithm/fibonacci.h"
#include "algorithm/quick_sort.h"
#include "algorithm/factorial.h"

int main() {
  // algorithm
  // 1. factorial
  printf("3! = %d\n", Factorial(3));
  printf("3! = %d\n", FactorialByIteration(3));

  // 2. fibonacci
  printf("Fibonacci(3): %d\n", Fibonacci(3));
  printf("Fibonacci(5): %d\n", Fibonacci(5));
  printf("Fibonacci(10): %d\n", Fibonacci(10));
  printf("FibonacciByIteration(10): %d\n", FibonacciByIteration(10));

  // 3. quick sort
  TestQuickSort();

  return 0;
}

