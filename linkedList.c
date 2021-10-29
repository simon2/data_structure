#include <stdio.h>
#include <stdlib.h>

typedef struct Node Node;

struct Node{
  int value;
  Node* next;
};

Node* createNode(int value);
Node* insert(Node* node, int x, int index);
void delete(Node* node, int index);
void traverse(Node* node);
int get(Node* node, int index);
int search(Node* node, int data);

int main(){
  int firstV;
  printf("Please input the value for the first node:");
  scanf("%ld",&firstV);
  Node* node = createNode(firstV);
  insert(node,5,1);
  traverse(node);
  insert(node,10,2);
  traverse(node);
  insert(node,15,3);
  traverse(node);
  delete(node,3);
  traverse(node);
  delete(node,1);
  traverse(node);
  get(node,2);
  printf("%ld\n",search(node,10));
  return 0;
}

Node* createNode(int value){
  Node* node = (Node*)malloc(sizeof(Node));
  node->value = value;
  node->next = NULL;
  return node;
}

Node* insert(Node* node, int x, int index){
  int i;
  Node* temp = node;
  for(i=0;i<index-1;i++){
    if(temp == NULL){
      printf("input index is invalid!\n");
    }else{
      temp = temp -> next;
    }
  }
  Node* newNode = createNode(x);
  newNode->next = temp->next;
  temp->next = newNode;
  return node;
}

void delete(Node* node, int index){
  int i;
  Node* temp = node;
  for(i=0;i<index-1;i++){
    if(temp == NULL){//index should not larger than length.
      printf("input index is invalid!\n");
      return;
    }else{
      temp = temp -> next;
    }
  }
  if(temp == NULL){//when linkedlist is empty.
    printf("input index is invalid!\n");
    return;
  }
  Node* temp2 = temp -> next;
  if(temp2 == NULL){
    printf("input index is invalid\n");
  }else{
    temp -> next = temp2 -> next;
    temp2 -> next = NULL;
  }
}

int get(Node* node, int index){
  int i;
  Node* temp = node;
  while(temp != NULL && i < index){
    temp = temp -> next;
    i++;
  }
  if(temp == NULL){
    return -1;
  }
  return temp->value;
}

void traverse(Node* node){
  int i;
  Node* temp = node;
  while(temp != NULL){
    printf("%ld ",temp->value);
    temp = temp -> next;
  }
  printf("\n");
}

int search(Node* node, int data){
  Node* temp = node;
  int i = 0;
  while(temp != NULL){
    if(temp->value == data){
      break;
    }else{
      temp = temp -> next;
      i++;
    }
  }
  if(temp == NULL){
    i = -1;
  }
  return i;
}
