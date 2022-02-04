//
// Created by 康晓宁 on 2022/2/4.
//
#include <stdio.h>

void PointerOperationsExample() {
  int array[] = {1, 2, 3, 4, 5};
  int *p = array;
  printf("array[2]: %d\n", array[2]);
  printf("*(p + 2): %d\n", *(p + 2));
  printf("*(array + 2): %d\n", *(array + 2));
  printf("p[2]: %d\n", p[2]);
  printf("2[array]: %d\n", 2[array]); // not recommend
}
