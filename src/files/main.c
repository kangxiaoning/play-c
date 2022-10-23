#include <stdio.h>
#include <errno.h>
#include <string.h>
#include "../io_util/io_util.h"

void ReadFile() {
  FILE* file = fopen("cmake_install.cmake", "r");

  if (file) {
    int next_char = getc(file);
    while (next_char != EOF) {
      putchar(next_char);
      next_char = getc(file);
    }

    fflush(stdout);
    fclose(file);
  } else {
    PRINT_INT(errno);
    puts(strerror(errno));
    perror("fopen");
  }
}

void MeaningOfErrno(int max_error_number) {
  for (int i = 0; i < max_error_number; ++i) {
    printf("%d: ", i);
    puts(strerror(i));
  }
}

__attribute__((unused)) void TestEof() {
  while (1) {
    int next_lint = getchar();
    if (next_lint == EOF) {
      break;
    } else if (next_lint == '\n') {
      continue;
    }
    // print EOF on macOS after press Ctrl-D
    printf("%c\n", next_lint);
    fflush(stdout);
  }
}

// define copy error code
#define COPY_SUCCESS 0
#define COPY_ILLEGAL_ARGUMENTS (-1)
#define COPY_SRC_OPEN_ERROR (-2)
#define COPY_SRC_READ_ERROR (-3)
#define COPY_DST_OPEN_ERROR (-4)
#define COPY_DST_WRITE_ERROR (-5)
#define COPY_UNKNOWN_ERROR (-100)

int CopyFileV1(char const* src, char const* dest) {
  // check arguments
  if (!src || !dest) {
    return COPY_ILLEGAL_ARGUMENTS;
  }

  // open source file
  FILE* src_file = fopen(src, "rb");
  if (!src_file) {
    return COPY_SRC_OPEN_ERROR;
  }

  // open destination file
  FILE* dest_file = fopen(dest, "wb");
  if (!dest_file) {
    // note: src_file was opened currently
    // if dest_file open failed, we need to close src_file before return error
    fclose(src_file);
    return COPY_DST_OPEN_ERROR;
  }

  // begin copy
  int result;
  while (1) {
    // read from src_file
    int next = fgetc(src_file);
    if (next == EOF) {
      if (ferror(src_file)) {
        result = COPY_SRC_READ_ERROR;
      } else if (feof(src_file)) {
        result = COPY_SUCCESS;
      } else {
        result = COPY_UNKNOWN_ERROR;
      }
      break;
    }

    // write to dest_file
    if (fputc(next, dest_file) == EOF) {
      result = COPY_DST_WRITE_ERROR;
      break;
    }
  }

  // close opened files
  fclose(src_file);
  fclose(dest_file);

  return result;
}

int main() {
  // fopen example
  ReadFile();

  // meaning of errno
  MeaningOfErrno(10);

  // test EOFj
  // TestEof();

  // copy file
  int result = CopyFileV1("cmake_install.cmake.not.exist",
                          "/Users/kangxiaoning/Downloads/temp/cmake_install.cmake");
  PRINT_INT(result);
  result = CopyFileV1("cmake_install.cmake", "/Users/kangxiaoning/Downloads/temp/cmake_install.cmake");
  PRINT_INT(result);

  return 0;
}