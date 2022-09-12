//
// Created by 康晓宁 on 2022/9/12.
//
#include "../io_util/io_util.h"
#include <errno.h>
#include <stdlib.h>

int main(void) {

  // string conversion
  char const *const kStringToParse = "666 12345678901234567890 999 -123 333this is end";
  PRINTLNF("Parse: %s", kStringToParse);

  char const *start = kStringToParse;
  char *end;

  while (1) {
    errno = 0;
    const long i = strtol(start, &end, 10);

    if (start == end) {
      break;
    }
    printf("'%.*s'\t ==> %ld\n", (int) (end - start), start, i);

    if (errno == ERANGE) {
      perror("");
    }

    start = end;
  }
  PRINTLNF("Left: %s", end);

  return 0;
}