//
// Created by 康晓宁 on 2022/2/3.
//

#include <time.h>
#include <stdlib.h>
#include <stdio.h>

void PrintArray(int array[], int length) {
  for (int i = 0; i < length; ++i) {
    printf("%d ", array[i]);
  }
  printf("\n");
}

// 1. quick sort version 1
void SwapElements(int array[], int first, int second) {
  int temp = array[first];
  array[first] = array[second];
  array[second] = temp;
}

void ShuffleArrayV1(int array[], int length) {
  srand(time(NULL));
  for (int i = length - 1; i > 0; --i) {
    int random_number = rand() % length;
    SwapElements(array, i, random_number);
  }
}

int PartitionV1(int array[], int low, int high) {
  // set pivot
  int pivot = array[high];
  int partition = low;
  for (int i = low; i < high; ++i) {
    if (array[i] < pivot) {
      SwapElements(array, i, partition);
      partition += 1;
    }
  }
  SwapElements(array, partition, high);
  return partition;
}

void QuickSortV1(int array[], int low, int high) {
  if (low >= high) {
    return;
  }
  int partition = PartitionV1(array, low, high);
  QuickSortV1(array, low, partition - 1);
  QuickSortV1(array, partition + 1, high);
}

// 2. quick sort version 2
void SwapInt(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

void Shuffle(int *array, int length) {
  srand(time(NULL));
  for (int i = length - 1; i > 0; --i) {
    int random_number = rand() % i;
    SwapInt(array + i, array + random_number);
  }
}

int *Partition(int *low, int *high) {
  // prevent overflow
  // pivot is in the middle of p and q
  int pivot = *(low + (high - low) / 2);

  int *p = low;
  int *q = high;
  while (1) {
    // move p to right until *p < pivot
    while (*p < pivot) {
      p++;
    }
    // move q to left until *q > pivot
    while (*q > pivot) {
      q--;
    }

    // if p >= q, the array is split to two partition
    // all elements on the left side of array[p] less or equal than array[p]
    // all elements on the right side of array[p] greater or equal than array[p]
    if (p >= q) {
      break;
    }

    // if the loop does not break
    // at this point, array[p] >= pivot or array[q] <= pivot
    // swap *p and *p
    SwapInt(p, q);
    // and move p to the right
    p++;
    // and move q to the left
    q--;
  }

  return q;
}

void QuickSortV2(int *low, int *high) {
  if (low >= high) {
    return;
  }
  int *partition = Partition(low, high);
  QuickSortV2(low, partition);
  QuickSortV2(partition + 1, high);
}

void TestQuickSort() {
  int player_count = 50;

  // init array
  int player[player_count];
  for (int i = 0; i < player_count; ++i) {
    player[i] = i;
  }

  // sorted
  PrintArray(player, player_count);

  // shuffle
  printf("ShuffleArrayV1:\n");
  ShuffleArrayV1(player, player_count);
  PrintArray(player, player_count);

  // quick sort
  printf("QuickSortV1:\n");
  QuickSortV1(player, 0, player_count - 1);
  PrintArray(player, player_count);

  // shuffle
  printf("Shuffle:\n");
  Shuffle(player, player_count);
  PrintArray(player, player_count);

  // quick sort
  printf("QuickSortV2:\n");
  QuickSortV2(player, player + player_count - 1);
  PrintArray(player, player_count);

}