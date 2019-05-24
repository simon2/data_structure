#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

void insert(int* data, int x);
int delete(int* data);

int count = 0;

int main(){
  int a[SIZE] = {9,17,23,97,3,26,25,19,40,43};
  int *b;
  b = (int*)malloc(sizeof(int)*SIZE);
  int i;
  for(i=0;i<SIZE;i++){
    printf("%ld ", a[i]);
  }
  printf("\n");
  for(i=0;i<SIZE;i++){
    insert(b,a[i]);
  }
  for(i=0;i<SIZE;i++){
    printf("%ld ", b[i]);
  }
  printf("\n");
  for(i=0;i<SIZE;i++){
    printf("%ld ", delete(b));
  }
}

void insert(int* data, int x){
  if(count >= SIZE){
    printf("heap is already full!\n");
    return;
  }
  int index = count;
  while(index > 0){
    int parent = (index - 1)/2;
    if(x > data[parent]){
      data[index] = data[parent];//move parent to child. the last empty parent will be filled after loop.
      index = parent;
    }else{
      break;
    }
  }
  data[index] = x;//here fills the last empty parent.
  count++;
}

int delete(int* data){
  if(count <= 0){
    printf("heap is already empty!\n");
    return -1;
  }
  int temp;
  int result = data[0];
  data[0],temp = data[--count];
  int index = 0;
  while(index <= (count-1)/2){//until the last value's parent, this can make program easier because we don't need to consider whether this element has left child.
    int left = index * 2 + 1;
    int right = index * 2 + 2;
    if(right >= count){
      if(temp < data[left]){
	data[index] = data[left];
	index = left;
      }else{
	break;
      }
    }else{
      if(data[left] >= data[right]){
	if(temp < data[left]){
	  data[index] = data[left];
	  index = left;
	}else{
	  break;
	}
      }else{
	if(temp < data[right]){
	  data[index] = data[right];
	  index = right;
	}else{
	  break;
	}
      }
    }
  }
  data[index] = temp;
  return result;
}
