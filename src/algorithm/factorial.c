//
// Created by 康晓宁 on 2022/2/4.
//
#include "factorial.h"

unsigned int Factorial(unsigned int n) {
  if (n == 0) {
    return 1;
  } else {
    return n * Factorial(n - 1);
  }
}

unsigned int FactorialByIteration(unsigned int n) {
  unsigned int result = 1;

  for (unsigned int i = n; i > 0; --i) {
    result *= i;
  }
  return result;
}