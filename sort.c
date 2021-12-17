#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define N 10

void bubbleSort(int* a);
void insertSort(int* a);
void selectSort(int* a);
void shellSort(int* a);
void mergeSort(int* a, int left, int right);
void merge(int* a, int left, int mid, int right);
void quickSort(int*a, int left, int right);
void countingSort(int nums[], int n);
void radix_counting_sort(int *nums, int n, int exp, int radix);
void radix_sort(int *nums, int n);

int main(){
  int* a = (int*)malloc(sizeof(int)*N);
  int i;
  for(i=0;i<N;i++){
    a[i] = rand()%100 + 1;
    printf("%ld ", a[i]);
  }
  printf("\n");
  bubbleSort(a);
  //insertSort(a);
  //selectSort(a);
  //shellSort(a);
  //mergeSort(a,0,N-1);
  //quickSort(a,0,N);
  for(i=0;i<N;i++){
    printf("%ld ", a[i]);
  }
}

void bubbleSort(int* a){
  int length = N;
  int i;
  int didswap;
  while(length>0){
    didswap = 0;
    for(i=0;i<length-1;i++){
      if(a[i] > a[i+1]){
	int temp = a[i];
	a[i] = a[i+1];
	a[i+1] = temp;
	didswap = 1;
      }
    }
    length--;
    if(didswap==0){
      return;
    }
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

void shellSort(int* a){
  int i,j;
  int gap;
  int temp;
  for(gap=N>>1;gap>0;gap>>=1){
    for(i=gap;i<N;i++){
      temp = a[i];
      for(j=i-gap;j>=0&&a[j]>temp;j-=gap){
	a[j+gap] = a[j];
      }
      a[j+gap] = temp;
    }
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

void mergeSort(int* a, int left, int right){
  if(left<right){
    int mid = (left + right)/2;
    mergeSort(a,left,mid);
    mergeSort(a,mid+1,right);
    merge(a,left,mid,right);
  }
}

void merge(int*a, int left, int mid, int right){
  int* temp = (int*)malloc(sizeof(int)*(right-left+1));
  int l = left;
  int m = mid + 1;
  int i = 0;
  while(l <= mid && m <= right){
    if(a[l]<=a[m]){
      temp[i] = a[l];
      l++;
    }else{
      temp[i] = a[m];
      m++;
    }
    i++;
  }
  while(l<=mid){
    temp[i] = a[l];
    l++;
    i++;
  }
  while(m<=right){
    temp[i] = a[m];
    m++;
    i++;
  }
  for(i=left;i<=right;i++){
    a[i] = temp[i-left];
  }
}

void quickSort(int* a, int left, int right){
  int i,j,pivot;
  if(left < right){
    pivot = left;
    i = left;
    j = right;
    while(i < j){
      while(a[i] <= a[pivot] && i < right){
	i++;
      }
      while(a[j] > a[pivot] && j > left){
	j--;
      }
      if(i < j){
	int temp = a[i];
	a[i] = a[j];
	a[j] = temp;
      }
    }
    int temp = a[j];
    a[j] = a[pivot];
    a[pivot] = temp;
    quickSort(a,left,j-1);
    quickSort(a,j+1,right);
  }
}

void countingSort(int *nums, int n){
  int high = max(nums, n);
  int low = min(nums, n);
  int size = high - low + 1;
  int *output = (int *)malloc(sizeof(int) * n);
  int *count = (int *)malloc(sizeof(int) * size);
  int i;
  for(i=0; i<size; i++)
    count[i] = 0;
  for(i=0;i<size;i++)
    count[nums[i]-low]++;
  for(i=1;i<size;i++)
    count[i] += count[i-1];
  for(i=0;i<n;i++){
    int num = nums[i];
    int pos = count[num - low] - 1;
    output[pos] = nums[i];
    count[num - low]--;
  }
  for(i=0;i<n;i++){
    nums[i] = output[i];
  }
  free(output);
  free(count);
}

void radix_counting_sort(int *nums, int n, int exp, int radix){
  int *output = (int *)malloc(sizeof(int) * n);
  int *count = (int *)malloc(sizeof(int) * radix);

  int i;
  for(i=0;i<radix;i++)
    count[i] = 0;
  for(i=0;i<n;i++)
    count[(nums[i]/exp)%radix]++;
  for(i=1;i<radix;i++)
    count[i] += count[i-1];
  for(i=n-1;i>=0;i--){
    int num = nums[i];
    output[count[(num/exp)%radix]-1]--;
    count[(num/exp)%radix]--;
  }
  for(i=0;i<n;i++){
    nums[i] = output[i];
  }
}

void radix_sort(int *nums, int n){
  int radix = 10;
  int mx = max(nums, n);

  int exp;
  for(exp=1;mx/exp>0;exp*=radix)
    radix_counting_sort(nums, n, exp, radix);
}