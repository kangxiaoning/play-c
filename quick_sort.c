//
// Created by 康晓宁 on 2022/2/3.
//

#include <time.h>
#include <stdlib.h>
#include <stdio.h>

void SwapElements(int array[], int first, int second) {
  int temp = array[first];
  array[first] = array[second];
  array[second] = temp;
}

void ShuffleArray(int array[], int length) {
  srand(time(NULL));
  for (int i = length - 1; i > 0; --i) {
    int random_number = rand() % length;
    SwapElements(array, i, random_number);
  }
}

int Partition(int array[], int low, int high) {
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

void QuickSort(int array[], int low, int high) {
  if (low >= high) {
    return;
  }
  int partition = Partition(array, low, high);
  QuickSort(array, low, partition - 1);
  QuickSort(array, partition + 1, high);
}

void PrintArray(int array[], int length) {
  for (int i = 0; i < length; ++i) {
    printf("%d ", array[i]);
  }
  printf("\n");
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
  ShuffleArray(player, player_count);
  PrintArray(player, player_count);

  // quick sort
  QuickSort(player, 0, player_count);
  PrintArray(player, player_count);

}