//
// Created by 康晓宁 on 2022/2/6.
//

#include <stdio.h>

// C语言中的enum是整型
typedef enum Day {
  SUNDAY,
  MONDAY = 10,
  TUESDAY,
  WEDNESDAY,
  THURSDAY,
  FRIDAY,
  SATURDAY
} Day;

// 1. Enum
void EnumExample() {
  // 枚举赋值
  Day first = SUNDAY;
  Day second = MONDAY;
  Day third = TUESDAY;

  // 整型赋值
  Day fourth = 13;

  printf("first: %d\n", first);    // 0
  printf("second: %d\n", second);  // 10
  printf("third: %d\n", third);    // 11
  printf("fourth: %d\n", fourth);  // 13
}

// Union
// union类型是共享内存的，以size最大的字段作为结构体的大小
int IsBigEndianV1() {
  union {
    char c[2];
    short s;
  } value = {.s=0x100};
  return value.c[0] == 1;
}

// 指针版本
int IsBigEndianV2() {
  short s = 0x100;
  // 转换为字符数组指针
  char *p = (char *) &s;
  return p[0] == 1;
}

int main() {

  // 1. Enum
  EnumExample();

  // 2. Union
  printf("%d\n", IsBigEndianV1());
  // 指针版本
  printf("%d\n", IsBigEndianV2());

  return 0;
}