//
// Created by 康晓宁 on 2022/2/4.
//

#include "hanoi.h"
#include "guess_number.h"

int main() {
  
  // guess number
  GuessNumber();

  // The tower of hanoi
  Move(3, 'A', 'C', 'B');

  return 0;
}

