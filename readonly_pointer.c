//
// Created by 康晓宁 on 2022/2/3.
//

// const修饰左边内容，决定谁不能修改
// 如果const修饰变量，则变量不能修改
// 如果const修饰指针，则指针不能修改
void ReadonlyPointerExample() {
  int a = 5;
  int *p = &a;
  printf("&a: %#x\n", &a);
  printf(" p: %#x\n", p);

  // 1. int *const
  int *const kStarConstP = &a;
  printf("kStarConstP: %#x\n", kStarConstP);
  // 1.1 OK
  *kStarConstP = 2;
  printf("*kStarConstP = 2 : %s\n", (*kStarConstP == 2) ? "ok" : "error");
  // 1.2 ERROR
  int b = 9;
  // kStarConstP = &b;
  char error_1[] = "error: cannot assign to variable 'kStarConstP' with const-qualified type 'int *const'";
  printf("kStarConstP = &b : %s\n", error_1);

  // 2. int const *const
  int const *const kConstStarConstP = &a;
  // 2.1 ERROR
  // *kConstStarConstP = 3;
  char error_2[] = "error: read-only variable is not assignable";
  printf("*kConstStarConstP = 3 : %s\n", error_2);
  // 2.2 ERROR
  // kConstStarConstP = &b;
  char error_3[] = "error: cannot assign to variable 'kConstStarConstP' with const-qualified type 'const int *const'";
  printf("kConstStarConstP = &b : %s\n", error_3);

  // 3. int const *
  int const *k_const_star_p = &a;
  // 3.1 ERROR
  // *k_const_star_p = 4;
  char error_4[] = "error: read-only variable is not assignable";
  printf("*k_const_star_p = 4 : %s\n", error_4);
  // 3.2 OK
  k_const_star_p = &b;
  printf("k_const_star_p = &b : %s\n", (*k_const_star_p == 9) ? "ok" : "error");
}