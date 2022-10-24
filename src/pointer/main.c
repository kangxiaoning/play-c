//
// Created by 康晓宁 on 2022/2/4.
//

#include "readonly_pointer.h"
#include "pointer_operations.h"
#include "pointer_parameter_as_return_value.h"
#include "../include/io_util.h"

int main(void) {
  int a = 1;
  int b = 2;
  PRINT_INT(a);
  PRINT_INT(b);

  // 1. variable: read write
  // 1. pointer: read write
  int* p_1 = &a;
  PRINT_INT(*p_1);
  *p_1 = 11;
  PRINT_INT(*p_1);
  p_1 = &b;
  PRINT_INT(*p_1);

  // 2. variable: read write
  // 2. pointer: read only
  int* const p_2 = &a;
  PRINT_INT(*p_2);
  // error: cannot assign to variable 'p_2' with const-qualified type 'int *const'
  // p_2 = &b;
  *p_2 = 22;
  PRINT_INT(*p_2);

  // 3. variable: read only
  // 3. pointer: read write
  int const* p_3 = &a;
  PRINT_INT(*p_3);
  // error: read-only variable is not assignable
  // *p_2 = 33;
  p_3 = &b;
  PRINT_INT(*p_3);

  // 4. variable: read only
  // 4. pointer: read only
  int const* const p_4 = &a;
  PRINT_INT(*p_4);
  // error: cannot assign to variable 'p_4' with const-qualified type 'const int *const'
  // p_4 = &b;

  // error: read-only variable is not assignable
  // *p_4 = 22;

  // readonly_pointer
  ReadonlyPointerExample();

  // pointer_operations
  PointerOperationsExample();

  // pointer_parameter_as_return_value
  PointerParameterAsReturnValueExample();

  return 0;
}

