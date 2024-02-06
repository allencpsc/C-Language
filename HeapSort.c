#include <stdio.h>

void swap(int* a, int* b){
  int temp = *a;
  *a = *b;
  *b = temp;
}

void maxHeapify(int arr[], int sizeHeap, int i){
  int largest = i;
  int left = 2 * i + 1;
  int right = 2 * i + 2;
  if (left < sizeHeap && arr[left] > arr[largest]){
    largest = left;
  }
  if (right < sizeHeap && arr[right] > arr[largest]){
    largest = right;
  }
  if (largest != i){
    swap(&arr[i], &arr[largest]);
    maxHeapify(arr, sizeHeap, largest);
  }
}

void heapSort(int arr[], int sizeHeap){
  for(int i = sizeHeap / 2 - 1; i >= 0; i--){
    maxHeapify(arr, sizeHeap, i);
  }
  for (int i = sizeHeap - 1; i >= 0; i--){
    swap(&arr[0], &arr[i]);
    maxHeapify(arr, i, 0);
  }
}

void printArray(int arr[], int sizeHeap){
  for (int i = 0; i < sizeHeap; i++){
    printf("%d ", arr[i]);
  }
}

int main(){
  int arr[] = { 84,22,19,10,3,17,6,5,9 };
  int sizeHeap = sizeof(arr) / sizeof(arr[0]); //gives number of elements - divide total bytes by bytes/element
  heapSort(arr, sizeHeap);
  printf("Sorted array is:\n");
  printArray(arr, sizeHeap);
}
  
