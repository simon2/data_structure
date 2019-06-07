#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define N 10

void bubbleSort(int* a);
void insertSort(int* a);
void selectSort(int* a);

int main(){
  int* a = (int*)malloc(sizeof(int)*N);
  int i;
  for(i=0;i<N;i++){
    a[i] = rand()%100 + 1;
    printf("%ld ", a[i]);
  }
  printf("\n");
  //bubbleSort(a);
  //insertSort(a);
  selectSort(a);
  for(i=0;i<N;i++){
    printf("%ld ", a[i]);
  }
}

void bubbleSort(int* a){
  int length = N;
  int i;
  while(length>0){
    for(i=0;i<length-1;i++){
      if(a[i] > a[i+1]){
	int temp = a[i];
	a[i] = a[i+1];
	a[i+1] = temp;
      }
    }
    length--;
  }
}

void insertSort(int* a){
  int i,j;
  for(i=1;i<N;i++){
    int temp = a[i];
    for(j=i-1;j>=0;j--){
      if(a[j] > temp){
	a[j+1] = a[j];
      }else{
	break;
      }
    }
    a[j+1] = temp;
  }
}

void selectSort(int* a){
  int i,j;
  for(i=0;i<N;i++){
    int min = INT_MAX;
    int min_index = -1;
    for(j=i;j<N;j++){
      if(a[j]<min){
	min = a[j];
	min_index = j;
      }
    }
    int temp = a[i];
    a[i] = a[min_index];
    a[min_index] = temp;
  }
}
