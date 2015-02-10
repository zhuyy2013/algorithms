#include <stdio.h>
#include <stdlib.h>  //srand and rand 
#include <string.h>  //memcpy
#include <time.h>    //time

//swap two value in one array
void Swap(int *array, int a, int b) {
  int tmp = array[a];
  array[a] = array[b];
  array[b] = tmp;
}

//check final array order
bool CheckOrder(int *array, int n) {
  int i = 0;
  while (i < n - 1 && array[i] <= array[i+1]) i++;
  if(i == n - 1) return true;
  else return false;
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

void MergeSort(int *array, int n) {
  if( n < 2 ) {
    InsertionSort(array, n);
    return;
  }
  int pivot = n/2;
  MergeSort(array, pivot);
  MergeSort(array + pivot, n - pivot);
  int i = 0, j = pivot, k = 0;
  int *tmp_array = new int[n];
  while(k < n) {
    while(k < n && i < pivot && array[i] <= array[j]) 
      tmp_array[k++] = array[i++];
    while(k < n && j < n && array[j] <= array[i]) 
      tmp_array[k++] = array[j++];
    if(i >= pivot)
      while(k < n) tmp_array[k++] = array[j++];
    if(j >= n)
      while(k < n) tmp_array[k++] = array[i++];
  }
  memcpy(array, tmp_array, sizeof(int)*n);
  delete[] tmp_array; 
}

int main()
{
  srand(time(NULL));
  int test_size = 10000;
  int *test_array = new int[test_size];
  for(int i = 0; i < test_size; ++i)
    test_array[i] = rand() % test_size;  

  //BubbleSort(test_array, test_size);
  //InsertionSort(test_array, 10);
  //QuickSort(test_array, 0, 9);
  MergeSort(test_array, test_size);

  printf("%s\n", CheckOrder(test_array, test_size) ? "Pass" : "Fail");
  return 0;
}
