#include "stdio.h"

// calculator
#define ADD '+'
#define SUB '-'
#define MULTIPLY '*'
#define DIVIDE '/'
#define REM '%'

void Calculator(void) {
  int left;
  int right;
  char operator;

  char command;

  do {

    printf("Please input an expression: \n");
    scanf("%d %c %d", &left, &operator, &right);

    int result;

    switch (operator) {
      case ADD:result = left + right;
        break;
      case SUB:result = left - right;
        break;
      case MULTIPLY:result = left * right;
        break;
      case DIVIDE:result = left / right;
        break;
      case REM:result = left % right;
        break;
      default:printf("Unsupported operation: %c\n", operator);
        return;
    }

    printf("Result: %d\n", result);

    printf("Again? type 'q' for quit: \n");

    // user press the Enter key('\n') after the scan statement executed, so we need to capture '\n' char first
    getchar();

    // next we got the user input
    command = getchar();
    printf("command: %d\n", command);
  } while (command != 'q');
}