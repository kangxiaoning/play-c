//
// Created by 康晓宁 on 2022/2/4.
//

#include <stdio.h>
#include "hanoi.h"
#include "guess_number.h"
#include "calculator.h"

int main(void) {

  // guess number
  GuessNumber();

  // The tower of hanoi
  int count = 3;
  printf("The tower of hanoi, the count os plates is %d\n", count);
  Move(count, 'A', 'C', 'B');

  // Calculator
  Calculator();

  return 0;
}

