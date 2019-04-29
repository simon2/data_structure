#include <stdio.h>
#include <stdlib.h>

typedef struct Node Node;

struct Node{
  int value;
  Node* next;
};

Node createNode(int value);
void insert(Node* node, int x, int index);
void delete(Node* node, int index);
void travel(Node node);
int get(Node node, int index);

int main(){
  int firstV;
  printf("Please input the value for the first node:");
  scanf("%ld ",&firstV);
  Node node = createNode(firstV);
  insert(&node,5,1);
  travel(node);
  insert(&node,10,2);
  travel(node);
  insert(&node,15,3);
  travel(node);
  delete(&node,3);
  travel(node);
  delete(&node,1);
  travel(node);
  get(node,2);
  return 0;
}

Node createNode(int value){
  Node node;
  node.value = value;
  node.next = NULL;
  return node;
}

void insert(Node* node, int x, int index){
  int i;
  Node* temp = node;
  for(i=0;i<index-1;i++){
    if(temp == NULL){
      printf("input index is invalid!\n");
    }else{
      temp = temp -> next;
    }
  }
  Node newNode = createNode(x);
  newNode.next = temp->next;
  temp->next = &newNode;
}

void delete(Node* node, int index){
  int i;
  Node* temp = node;
  for(i=0;i<index-1;i++){
    if(temp == NULL){
      printf("input index is invalid!\n");
    }else{
      temp = temp -> next;
    }
  }
  Node* temp2 = temp -> next;
  if(temp2 == NULL){
    printf("input index is invalid\n");
  }else{
    temp -> next = temp2 -> next;
    temp2 -> next = NULL;
  }
}

int get(Node node, int index){
  int i;
  Node* temp = &node;
  for(i=0;i<index;i++){
    temp = temp -> next;
  }
  return temp->value;
}

void travel(Node node){
  int i;
  Node* temp = &node;
  while(temp != NULL){
    printf("%ld ",temp->value);
    temp = temp -> next;
  }
  printf("\n");
}
