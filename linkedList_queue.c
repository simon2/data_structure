#include <stdio.h>
#include <stdlib.h>

typedef struct Node Node;
struct Node{
  int value;
  Node* next;
};

Node* createNode(int value);
Node* enqueue(Node* head, int x);
int dequeue(Node** head);
int top(Node* head);
void traverse(Node* head);

int main(){
  int firstV;
  printf("please input the first element of the stack:");
  scanf("%ld",&firstV);
  Node* head = createNode(firstV);
  enqueue(head,5);
  traverse(head);
  enqueue(head,10);
  traverse(head);
  enqueue(head,15);
  traverse(head);
  enqueue(head,3);
  traverse(head);
  printf("%ld\n",dequeue(&head));
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

Node* enqueue(Node* head, int x){
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

int dequeue(Node** head){
  if(*head == NULL){
    printf("the stack is already empyt, no element can be pop!\n");
    return -1;
  }
  int result = (*head) -> value;
  *head = (*head) -> next;
  return result;
}

int top(Node* head){
  int result;
  if(head == NULL){
    printf("the stack is empty!");
    return -1;
  }
  result = head->value;
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
