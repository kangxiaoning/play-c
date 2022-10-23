//
// Created by 康晓宁 on 2022/9/12.
//
#include "../io_util/io_util.h"
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>

int main(void) {
  // compare string
  char* left = "Hello World!";
  char* right = "Hello C Programmers!";
  PRINT_INT(strcmp(left, right));
  PRINT_INT(strncmp(left, right, 5));

  // locate character in string
  char* result = strchr(left, 'l');
  puts(result);
  char* result_reverse = strrchr(left, 'l');
  puts(result_reverse);

  // find substring
  char* substring_position = strstr(left, "Wor");
  puts(substring_position);
  PRINT_LONG(substring_position - left);

  // locate multiple characters in string
  char* text = "C, 1972; C++, 1983; Java, 1995; Rust, 2010; Kotlin, 2011";
  char* break_set = ",;";

  int count = 0;
  char* p = text;
  do {
    p = strpbrk(p, break_set);
    if (p) {
      puts(p);
      p++;
      count++;
    }
  } while (p);
  PRINTLNF("Found %d characters.", count);

  // string tokenize
  char token_string[] = "C, 1972; C++, 1983; Java, 1995; Rust, 2010; Kotlin, 2011";
  typedef struct {
    char* name;
    int year;
  } Language;
  const char* language_break = ";";
  const char* field_break = ",";

  int language_capacity = 3;
  int language_size = 0;

  Language* languages = malloc(sizeof(Language) * language_capacity);
  if (!languages) {
    abort();
  }

  char* next = strtok(token_string, field_break);
  while (next) {
    Language language;
    language.name = next;

    next = strtok(NULL, language_break);
    if (next) {
      language.year = atoi(next);

      if (language_size + 1 >= language_capacity) {
        language_capacity *= 2;
        languages = realloc(languages, sizeof(Language) * language_capacity);
        if (!languages) {
          abort();
        }
      }

      languages[language_size++] = language;
      next = strtok(NULL, field_break);
    }
  }
  PRINTLNF("languages: %d", language_size);
  PRINTLNF("languages capacity: %d", language_capacity);

  for (int i = 0; i < language_size; ++i) {
    PRINTLNF("Language[name=%s, year=%d]", languages[i].name, languages[i].year);
  }

  free(languages);

  // string concat
  char src[] = "Hello World.";
  char dest[20] = "C: said: ";
  strcat(dest, src);
  puts(dest);

  char src_a[] = "Hello World.";
  char dest_a[20] = "C: said: ";
  strcpy(dest_a + strlen(dest_a), src_a);
  puts(dest_a);

  // memory operation and string operation function
  // memchr
  // strchr
  // memcmp
  // strcmp
  // memcpy
  // strcpy
  // memset
  // memmove

  // multiple bytes string and wide character string
  // PRINT_BOOL(iswalpha(L'A'));
  char mbs[] = "你好";
  wchar_t wcs[10];
  mbstowcs(wcs, mbs, 10);
  wprintf(L"%s\n", wcs);

  // string conversion
  char const* const kStringToParse = "666 12345678901234567890 999 -123 333this is end";
  PRINTLNF("Parse: %s", kStringToParse);

  char const* start = kStringToParse;
  char* end;

  while (1) {
    errno = 0;
    const long kI = strtol(start, &end, 10);

    if (start == end) {
      break;
    }
    printf("'%.*s'\t ==> %ld\n", (int) (end - start), start, kI);

    if (errno == ERANGE) {
      perror("");
    }

    start = end;
  }
  PRINTLNF("Left: %s", end);

  return 0;
}