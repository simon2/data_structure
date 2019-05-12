#include <stdio.h>
#include <stdlib.h>

typedef struct Node Node;
struct Node{
  int value;
  Node* next;
};

Node* createNode(int value);
Node* push(Node* head, int x);
int pop(Node* head);
int top(Node* head);
void travel(Node* head);

int main(){
  int firstV;
  printf("please input the first element of the stack:");
  scanf("%ld",&firstV);
  Node* head = createNode(firstV);
  push(head,5);
  travel(head);
  push(head,10);
  travel(head);
  push(head,15);
  travel(head);
  push(head,3);
  travel(head);
  printf("%ld\n",pop(head));
  travel(head);
  printf("%ld\n", top(head));
  travel(head);
}

Node* createNode(int data){
  Node* node = (Node*)malloc(sizeof(Node));
  node->value = data;
  node->next = NULL;
  return node;
}

Node* push(Node* head, int x){
  Node* newNode = (Node*)malloc(sizeof(Node));
  newNode->value = x;
  newNode->next = NULL;
  if(head == NULL){
    head = newNode;
  }else{
    Node* temp = head;
    while(temp->next != NULL){
      temp = temp -> next;
    }
    temp -> next = newNode;
  }
  return head;
}

int pop(Node* head){
  if(head == NULL){
    printf("the stack is already empyt, no element can be pop!\n");
    return -1;
  }
  int result;
  if(head->next == NULL){
    result = head -> value;
  }else{
    Node* temp = head;
    while(temp->next->next != NULL){
      temp = temp -> next;
    }
    result = temp->next->value;
    temp->next = NULL;
  }
  return result;
}

int top(Node* head){
  int result;
  if(head == NULL){
    printf("the stack is empty!");
    return -1;
  }
  Node* temp = head;
  while(temp->next != NULL){
    temp = temp -> next;
  }
  result = temp -> value;
  return result;
}

void travel(Node* head){
  Node* temp = head;
  while(temp != NULL){
    printf("%ld ", temp->value);
    temp = temp -> next;
  }
  printf("\n");
}
