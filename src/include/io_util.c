//
// Created by 康晓宁 on 2022/9/10.
//

#include <stdio.h>
#include <stdarg.h>

#include "io_util.h"

void Printlnf(const char *format, ...) {
  va_list args;
  va_start(args, format);
  vprintf(format, args);
  printf("\n");
  va_end(args);
}