#include <stdio.h>
#include <stdlib.h>

#define SIZE 10
#define EMPTY -1
#define DELETED -2

int hash(int value);
int search(int value);
void insert(int value);
void delete(int value);
void travel();

int hash_table[SIZE];
int count = 0;

int main(){
  int i;
  for(i=0;i<SIZE;i++){
    hash_table[i] = EMPTY;
  }
  travel();
  insert(1);
  travel();
  insert(2);
  travel();
  insert(3);
  travel();
  insert(4);
  travel();
  insert(5);
  travel();
  insert(6);
  travel();
  delete(1);
  travel();
  delete(6);
  travel();
}

int hash(int value){
  return value % 5;
}

int search(int value){
  int i;
  int hash_code = hash(value);
  for(i=hash_code;i<hash_code+SIZE;i++){
    int j = i % SIZE;
    if(hash_table[j]==EMPTY){
      return -1;
    }
    if(hash_table[j]==value){
      return j;
    }
  }
  return -1;
}

void insert(int value){
  if(count >= SIZE){
    printf("the hash table is already full!\n");
    return;
  }
  int i = hash(value);
  while(hash_table[i] != EMPTY && hash_table[i] != DELETED){
    i = (i + 1) % SIZE;
  }
  hash_table[i] = value;
  count++;
}

void delete(int value){
  int i;
  int hash_code = hash(value);
  for(i=hash_code;i<hash_code+SIZE;i++){
    int j = i % SIZE;
    if(hash_table[j]==EMPTY){
      return;
    }
    if(hash_table[j]==value){
      hash_table[j] = DELETED;
      count--;
      return;
    }
  }
}

void travel(){
  int i;
  for(i=0;i<SIZE;i++){
    if(hash_table[i] == EMPTY){
      printf("empty ");
    }else if(hash_table[i] == DELETED){
      printf("deleted ");
    }else{
      printf("%ld ",hash_table[i]);
    }
  }
  printf("\n");
}
