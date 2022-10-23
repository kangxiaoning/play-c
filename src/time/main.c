#include "../io_util/io_util.h"
#include <time.h>

#if defined(_WIN32)
#include <sys/timeb.h>
#elif defined(__unix__) || defined(__APPLE__)
#include <sys/time.h>
#endif

typedef long long LongTimeT;

LongTimeT TimeInMillisecond(void) {
#if defined(_WIN32)
  struct timeb time_buffer;
  ftime(&time_buffer);
  return time_buffer.time * 1000LL + time_buffer.millitm;
#elif defined(__unix__) || defined(__APPLE__)
  struct timeval time_value;
  gettimeofday(&time_value, NULL);
  return time_value.tv_sec * 1000LL + time_value.tv_usec / 1000;
#elif defined(__STDC__) && __STDC_VERSION__ == 201112L
  struct timespec timespec_value;
  timespec_get(&timespec_value,TIME_UTC);
  return timespec_value.tv_sec * 1000LL +timespec_value.tv_nsec/1000000;
#else
  time_t current_time = time(NULL);
  return current_time * 1000LL;
#endif
}

void Calendar() {
  time_t current_time;
  time(&current_time);
  PRINT_LONG(current_time);
  // get local time
  struct tm* calendar_time = localtime(&current_time);
  PRINT_INT(calendar_time->tm_year);
  PRINT_INT(calendar_time->tm_mon);
  PRINT_INT(calendar_time->tm_mday);
  PRINT_INT(calendar_time->tm_hour);
  PRINT_INT(calendar_time->tm_min);
  PRINT_INT(calendar_time->tm_sec);

  // result in a carry
  calendar_time->tm_sec = 70;
  time_t current_time_2 = mktime(calendar_time);
  PRINT_LONG(current_time_2);
  PRINT_INT(calendar_time->tm_year);
  PRINT_INT(calendar_time->tm_mon);
  PRINT_INT(calendar_time->tm_mday);
  PRINT_INT(calendar_time->tm_hour);
  PRINT_INT(calendar_time->tm_min);
  PRINT_INT(calendar_time->tm_sec);

  // get GMT time
  struct tm* gmt_time = gmtime(&current_time);
  PRINT_INT(gmt_time->tm_year);
  PRINT_INT(gmt_time->tm_mon);
  PRINT_INT(gmt_time->tm_mday);
  PRINT_INT(gmt_time->tm_hour);
  PRINT_INT(gmt_time->tm_min);
  PRINT_INT(gmt_time->tm_sec);
}

void FormatTime() {
  time_t current_time;
  time(&current_time);
  struct tm* calendar_time = localtime(&current_time);
  // asctime
  puts(asctime(calendar_time));

  // ctime
  puts(ctime(&current_time));

  // strftime
  // 2022-10-20 22:22:55
  char current_time_buffer[20];
  strftime(current_time_buffer, 20, "%Y-%m-%d %H:%M:%S", calendar_time);
  puts(current_time_buffer);
  strftime(current_time_buffer, 20, "%F %T", calendar_time);
  puts(current_time_buffer);
  strftime(current_time_buffer, 20, "%Y%m%d%H%M%S", calendar_time);
  puts(current_time_buffer);

  // millisecond
  long current_time_millisecond = TimeInMillisecond() % 1000;
  strftime(current_time_buffer, 20, "%Y%m%d%H%M%S", calendar_time);
  sprintf(current_time_buffer + 14, "%03ld", current_time_millisecond);
  puts(current_time_buffer);
}

void ParseTime() {

  time_t current_time;
  time(&current_time);
  struct tm* calendar_time = localtime(&current_time);

  // strftime
  // 2022-10-20 22:22:55
  char current_time_buffer[20];
  strftime(current_time_buffer, 20, "%F %T", calendar_time);

  // strptime
  struct tm parsed_time;
  char* unparsed_string = strptime(current_time_buffer, "%F %T", &parsed_time);

  PRINTLNF("unparsed strings: %s", unparsed_string);
  PRINT_INT(parsed_time.tm_year);
  PRINT_INT(parsed_time.tm_mon);
  PRINT_INT(parsed_time.tm_mday);
  PRINT_INT(parsed_time.tm_hour);
  PRINT_INT(parsed_time.tm_min);
  PRINT_INT(parsed_time.tm_sec);

  printf("---------------\n");

  char* time = "2022-10-22 09:07:34.234";
  unparsed_string = strptime(time, "%F %T", &parsed_time);

  PRINTLNF("unparsed strings: %s", unparsed_string);
  PRINT_INT(parsed_time.tm_year);
  PRINT_INT(parsed_time.tm_mon);
  PRINT_INT(parsed_time.tm_mday);
  PRINT_INT(parsed_time.tm_hour);
  PRINT_INT(parsed_time.tm_min);
  PRINT_INT(parsed_time.tm_sec);

  long millisecond;
  sscanf(unparsed_string, ".%3ld", &millisecond);
  PRINT_LONG(millisecond);

  // manually parse
  char* manual_time = "2022-10-22 09:07:34.234";
  struct tm manual_parsed_time;
  long manual_millisecond;
  sscanf(manual_time, "%4d-%2d-%2d %2d:%2d:%2d.%3ld", &manual_parsed_time.tm_year,
         &manual_parsed_time.tm_mon,
         &manual_parsed_time.tm_mday,
         &manual_parsed_time.tm_hour,
         &manual_parsed_time.tm_min,
         &manual_parsed_time.tm_sec,
         &manual_millisecond);

  manual_parsed_time.tm_year -= 1;
  manual_parsed_time.tm_mon -= 1;
  mktime(&manual_parsed_time);
  PRINT_INT(parsed_time.tm_year);
  PRINT_INT(parsed_time.tm_mon);
  PRINT_INT(parsed_time.tm_mday);
  PRINT_INT(parsed_time.tm_hour);
  PRINT_INT(parsed_time.tm_min);
  PRINT_INT(parsed_time.tm_sec);
  PRINT_LONG(manual_millisecond);
}

int main() {
  // current time
  time_t current_time;
  time(&current_time);
  PRINT_LONG(current_time);

  current_time = time(NULL);
  PRINT_LONG(current_time);

  // TimeInMillisecond
  PRINT_LLONG(TimeInMillisecond());
  PRINT_LLONG(TimeInMillisecond());
  PRINT_LLONG(TimeInMillisecond());
  PRINT_LLONG(TimeInMillisecond());

  // Calendar
  Calendar();

  // format time
  FormatTime();

  // parse time
  ParseTime();

  return 0;
}