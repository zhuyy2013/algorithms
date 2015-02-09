#include <stdio.h>

void Swap(int *array, int a, int b) {
  int tmp = array[a];
  array[a] = array[b];
  array[b] = tmp;
}

void BubbleSort(int *array, int size) {
  int tmp, i, j;
  for (i = 0; i < size; ++i) {
    for (j = 0; j < size - i - 1; ++j) {
      if (array[j] > array[j+1]) Swap(array, j, j+1);
    }
  }
}

void InsertionSort(int *array, int size) {
  int i, j, key;
  for (i = 1; i < size; ++i) {
    key = array[i];
    j = i - 1;
    while (j >= 0 && array[j] > key) {
      array[j+1] = array[j];
      --j;
    }
    array[j+1] = key;
  }
}

void QuickSort(int *array, int begin, int end) {
  if (begin >= end) return;
  Swap(array, (begin + end)/2, end);
  int i = begin, j = end - 1;
  while (i < j) {
    while (array[i] < array[end]) ++i;
    while (array[j] > array[end]) --j;
    if (i < j) Swap(array, i, j);
  }
  i = end;
  while(i > 0 && array[i-1] > array[i]) {
    Swap(array, i - 1, i);
    --i;
  }
  QuickSort(array, begin, i - 1);
  QuickSort(array, i + 1, end);
}

int main()
{
  int test_array[10] = { 11, 2, 33, 24, 65, 16, 7, 18, 29, 10 };
  //BubbleSort(test_array, 10);
  //InsertionSort(test_array, 10);
  QuickSort(test_array, 0, 9);
  for (int i = 0; i < 10; ++i) printf("%d ", test_array[i]);
  printf("\n");
  return 0;
}
