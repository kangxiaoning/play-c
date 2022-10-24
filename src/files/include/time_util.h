//
// Created by 康晓宁 on 2022/10/24.
//

#ifndef PLAY_C_SRC_FILES_INCLUDE_TIME_UTIL_H_
#define PLAY_C_SRC_FILES_INCLUDE_TIME_UTIL_H_

#include "../../include/io_util.h"

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
  timespec_get(&timespec_value, TIME_UTC);
  return timespec_value.tv_sec * 1000LL + timespec_value.tv_nsec / 1000000;
#else
  time_t current_time = time(NULL);
  return current_time * 1000LL;
#endif
}

__attribute__((unused)) void TimeCost(char const* msg) {
  static LongTimeT start_time = 0;
  if (msg && start_time != 0) {
    LongTimeT current_time = TimeInMillisecond();
    PRINTLNF("%s costs: %lld", msg, current_time - start_time);
  }
  start_time = TimeInMillisecond();
}

#endif //PLAY_C_SRC_FILES_INCLUDE_TIME_UTIL_H_
