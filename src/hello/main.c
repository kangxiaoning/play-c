#include <stdio.h>
#include "../io_util/io_util.h"
#include <stdlib.h>
#include <ctype.h>

int main(void) {

  PRINT_INT(atoi("1234"));
  PRINT_INT(atoi("-1234"));
  PRINT_INT(atoi("    1234hello"));
  PRINT_INT(atof("0x10"));

  return 0;
}