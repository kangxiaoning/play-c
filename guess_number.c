#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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
  scanf("%d", &max_number);

  int max_number_of_attempts = MaxNumberOfAttempts(max_number);

  // set random number
  // rand() default range is [0, 0x7fff]
  srand(time(NULL));
  // magic_number range is [0, 100]
  int magic_number = rand() % (max_number + 1);

  // loop guess
  int count = 0;
  while (count < max_number_of_attempts) {
    printf("\nYou have %d times to complete the game.\n", max_number_of_attempts - count);
    int user_input;
    puts("Please input a number:");
    scanf("%d", &user_input);
    count += 1;

    if (user_input > magic_number) {
      puts("Your number is bigger!");
    } else if (user_input < magic_number) {
      puts("Your number is smaller!");
    } else {
      puts("YES! You got it!");
      break;
    }
  }

}