#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

typedef struct Node Node;
struct Node{
  int key;
  int value;
  Node* next;
};

int hash(int key);
int search(int key);
void insert(int key, int value);
void delete(int key);
void traverse();

Node** hash_table;

int main(){
  hash_table = (Node**)malloc(sizeof(Node*)*SIZE);
  int i;
  for(i=0;i<SIZE;i++){
    hash_table[i] = NULL;
  }
  traverse();
  insert(1,1);
  traverse();
  insert(2,2);
  traverse();
  insert(3,3);
  traverse();
  insert(4,4);
  traverse();
  insert(5,5);
  traverse();
  insert(6,6);
  traverse();
  delete(1);
  traverse();
  delete(6);
  traverse();
}

int hash(int key){
  return key % 5;
}

int search(int key){
  int hash_code = hash(key);
  Node *p = hash_table[hash_code];
  while(p){
    if(p->key == key){
      return p->value;
    }
    p = p->next;
  }
  return -1;
}

void insert(int key, int value){
  int hash_code = hash(key);
  Node* newNode = (Node*)malloc(sizeof(Node));
  newNode->key = key;
  newNode->value = value;
  newNode->next = NULL;
  Node *p = hash_table[hash_code];
  if(p==NULL){
    hash_table[hash_code] = newNode;
    return;
  }
  while(p->next){
    p = p->next;
  }
  p->next = newNode;
}

void delete(int key){
  int hash_code = hash(key);
  Node *p = hash_table[hash_code];
  if(p==NULL){
    return;
  }
  if(p->key == key){
    hash_table[hash_code] = p->next;
    free(p);
    return;
  }
  Node *prev = p;
  p = p -> next;
  while(p){
    if(p->key == key){
      prev->next = p->next;
      free(p);
      return;
    }
    prev = p;
    p = p -> next;
  }
}

void traverse(){
  int i;
  for(i=0;i<SIZE;i++){
    printf("hash_code:%ld: ",i);
    Node *p = hash_table[i];
    while(p){
      printf("%ld ",p->value);
      p = p->next;
    }
    printf("\n");
  }
  printf("\n");
}
