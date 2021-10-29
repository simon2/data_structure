#include <stdio.h>
#include <stdlib.h>

typedef struct Node Node;
struct Node{
  int value;
  Node* next;
};

Node* createNode(int value);
Node* push(Node* head, int x);
int pop(Node** head);
int top(Node* head);
void traverse(Node* head);

int main(){
  int firstV;
  printf("please input the first element of the stack:");
  scanf("%ld",&firstV);
  Node* head = createNode(firstV);
  head = push(head,5);
  traverse(head);
  head = push(head,10);
  traverse(head);
  head = push(head,15);
  traverse(head);
  head = push(head,3);
  traverse(head);
  printf("%ld\n",pop(&head));
  traverse(head);
  printf("%ld\n", top(head));
  traverse(head);
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
    newNode->next = head;
    head = newNode;
  }
  return head;
}

int pop(Node** head){
  if(head == NULL){
    printf("the stack is already empyt, no element can be pop!\n");
    return -1;
  }
  int result = (*head) -> value;
  Node* temp = *head;
  *head = (*head) -> next;
  free(temp);
  return result;
}

int top(Node* head){
  int result;
  if(head == NULL){
    printf("the stack is empty!");
    return -1;
  }
  result = head -> value;
  return result;
}

void traverse(Node* head){
  Node* temp = head;
  while(temp != NULL){
    printf("%ld ", temp->value);
    temp = temp -> next;
  }
  printf("\n");
}
