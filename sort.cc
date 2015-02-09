#include <stdio.h>

void BubbleSort(int *array, int size) {
  int tmp, i, j;
  for (i = 0; i < size; ++i) {
    for (j = 0; j < size - i - 1; ++j) {
      if (array[j] > array[j+1]) {
        tmp = array[j];
        array[j] = array[j+1];
        array[j+1] = tmp;
      }
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

int main()
{
  int test_array[10] = { 11, 2, 33, 24, 65, 16, 7, 18, 29, 10 };
  //BubbleSort(test_array, 10);
  InsertionSort(test_array, 10);
  for (int i = 0; i < 10; ++i) printf("%d ", test_array[i]);
  printf("\n");
  return 0;
}
