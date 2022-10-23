#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "guess_number.h"

// The maximum number of attempts is determined by binary search method
int MaxNumberOfAttempts(int max_number) {
  int result = 0;
  int number = max_number;
  while (number >= 2) {
    number = number / 2;
    result += 1;
  };

  // plus 1 times in case of mistake
  if (pow(2, result) < max_number) {
    result += 2;
  } else {
    result += 1;
  }

  return result;
}

void GuessNumber() {
  // input max number
  int max_number;
  printf("Please input the max number.\n");
  fflush(stdout);
  scanf("%d", &max_number);
  fflush(stdin);

  int max_number_of_attempts = MaxNumberOfAttempts(max_number);

  // set random number
  // rand() default range is [0, 0x7fff]
  srand(time(NULL));
  fflush(stdin);
  // magic_number range is [0, 100]
  int magic_number = rand() % (max_number + 1);

  // loop guess
  int count = 0;
  while (count < max_number_of_attempts) {
    printf("\nYou have %d times to complete the game.\n", max_number_of_attempts - count);
    fflush(stdout);
    int user_input;
    puts("Please input a number:");
    fflush(stdout);
    scanf("%d", &user_input);
    fflush(stdin);
    count += 1;

    if (user_input > magic_number) {
      puts("Your number is bigger!");
      fflush(stdout);
    } else if (user_input < magic_number) {
      puts("Your number is smaller!");
      fflush(stdout);
    } else {
      puts("YES! You got it!");
      fflush(stdout);
      break;
    }
  }

}