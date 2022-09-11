#include <stdio.h>
#include "../io_util/io_util.h"
#include <stdlib.h>

int main(void) {

  double x = 3.0;
  double y = 4.0;

  typeof(x) a = 5.0;
  PRINT_DOUBLE(a);

  return 0;
}