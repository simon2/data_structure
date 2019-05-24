#include <stdio.h>
#include <stdlib.h>

void heapify(int* data, int i, int size);//maintaining the heap.
void buildHeap(int* data);//build a heap from original data by heapify.
void heapsort(int* data);

int size = 10;

int main(){
  int a[10] = {9,17,23,97,3,26,25,19,40,43};
  heapsort(&a[0]);
  int i;
  for(i=0;i<size;i++){
    printf("%ld ", a[i]);
  }
}

void heapify(int* data, int index, int size){
  int left = index * 2 + 1;
  int right = index * 2 + 2;
  int largest;
  if(left < size && data[left] > data[index]){
    largest = left;
  }else{
    largest = index;
  }
  if(right < size && data[right] > data[largest]){
    largest = right;
  }
  if(largest != index){
    int temp = data[index];
    data[index] = data[largest];
    data[largest] = temp;
    heapify(data, largest,size);
  }
}

void build_heap(int* data){
  int i;
  for(i=(size-1)/2;i>=0;i--){
    heapify(data,i,size);
  }
}

void heapsort(int* data){
  build_heap(data);
  int i;
  int n = size;
  for(i=size-1;i>0;i--){
    int temp = data[0];
    data[0] = data[i];
    data[i] = temp;
    n--;
    heapify(data,0,n);
  }
}
