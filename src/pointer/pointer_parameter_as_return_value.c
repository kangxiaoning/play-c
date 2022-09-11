//
// Created by 康晓宁 on 2022/2/4.
//

#include <stdio.h>
#include "pointer_parameter_as_return_value.h"

int SumIntArrayV1(int array[], int length) {
  int sum = 0;
  for (int i = 0; i < length; ++i) {
    sum += array[i];
  }
  // 通过 Compiler Explorer 查看编译后的指令
  // 1. return sum 会把该函数call stack内存中的值复制到寄存器
  return sum;
}

void SumIntArrayV2(int array[], int length, int *sum) {
  *sum = 0;
  for (int i = 0; i < length; ++i) {
    *sum += array[i];
  }
}

void PointerParameterAsReturnValueExample() {
  int array[] = {0, 1, 2, 3, 4};
  // 通过 Compiler Explorer 查看编译后的指令
  // 2. 从寄存器复制到调用函数定义到变量内存中
  int sum_1 = SumIntArrayV1(array, 5);
  printf("sum_1: %d\n", sum_1);

  int sum_2;
  // 通过 Compiler Explorer 查看编译后的指令
  // 好处：
  // 1. 避免了返回值时寄存器与内存之间的复制开销
  // 2. 提供了多个返回值的能力
  SumIntArrayV2(array, 5, &sum_2);
  printf("sum_1: %d\n", sum_2);
}