//
// Created by 康晓宁 on 2022/2/4.
//

#include "hanoi.h"
#include "guess_number.h"
#include "calculator.h"

int main(void) {

  // guess number
  GuessNumber();

  // The tower of hanoi
  Move(3, 'A', 'C', 'B');

  // Calculator
  Calculator();

  return 0;
}

