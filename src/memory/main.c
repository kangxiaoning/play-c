//
// Created by 康晓宁 on 2022/2/5.
//

#include <stdlib.h>
#include <stdio.h>

// malloc example
void MallocExample() {
  // 1. malloc
  int length = 5;

  // 1.1 只分配 sizeof(int) 大小，如下代码也可以执行
  // int *array = malloc(sizeof(int));

  // 1.2 分配 sizeof(int) * length
  int *array = malloc(sizeof(int) * length);

  // 2. init
  for (int i = 0; i < length; ++i) {
    // 初始化前的值，不同编译器实现不一样
    printf("%d = %d\n", i, array[i]);
    // 初始化
    array[i] = i;
  }

  // 3. use
  // 3.1 数组越界也能打印
  // for (int i = 0; i <= length; ++i) {
  // 3.2 数组边界内正常使用
  for (int i = 0; i < length; ++i) {
    printf("%d, ", array[i]);
  }
  printf("\n");

  // 4. free
  free(array);
}

// init pointer
// 注意指针的传递，指针本身会被复制，因此修改指针指向的变量，需要传递指针的地址
void InitPointer(int **ptr, int length, int default_value) {
  *ptr = malloc(sizeof(int) * length);
  for (int i = 0; i < length; ++i) {
    (*ptr)[i] = default_value;
  }
}

void InitPointerExample() {
  int *array;
  int length = 5;

  // 1. malloc and init
  InitPointer(&array, length, 10);

  // 2. use
  for (int i = 0; i < length; ++i) {
    printf("%d = %d\n", i, array[i]);
    array[i] = i;
  }

  for (int i = 0; i < length; ++i) {
    printf("%d ", array[i]);
  }
  printf("\n");

  // 3. free
  free(array);
}

// reallocate example
void ReallocateExample() {
  int *array;
  int length = 5;

  // 1. malloc and init
  InitPointer(&array, length, 10);

  // 2. use
  for (int i = 0; i < length; ++i) {
    printf("%d = %d\n", i, array[i]);
    array[i] = i;
  }

  for (int i = 0; i < length; ++i) {
    printf("%d ", array[i]);
  }
  printf("\n");

  // 3. reallocate
  // 动态分配后，未使用部分的内存是否会初始化，不同编译器实现不一样，MAC上看到是0
  array = realloc(array, sizeof(int) * length * 2);

  for (int i = 0; i < length * 2; ++i) {
    printf("%d ", array[i]);
  }
  printf("\n");

  // 4. free
  free(array);
}

int main() {
  // malloc example
  MallocExample();

  // init pointer example
  InitPointerExample();

  // reallocate example
  ReallocateExample();

  return 0;
}