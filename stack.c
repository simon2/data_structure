#include <stdio.h>
#include <stdlib.h>

typedef struct Stack{
  int* array;
  int head;
  int length;
}Stack;

Stack createStack(int length);
void push(Stack* stack, int x);
int pop(Stack* stack);
int top(Stack stack);
void traverse(Stack stack);

int main(){
  int length;
  printf("please input the lentgh of the stack:");
  scanf("%ld",&length);
  Stack stack = createStack(length);
  push(&stack,5);
  traverse(stack);
  push(&stack,10);
  traverse(stack);
  push(&stack,15);
  traverse(stack);
  push(&stack,3);
  traverse(stack);
  printf("%ld\n",pop(&stack));
  traverse(stack);
  printf("%ld\n", top(stack));
  traverse(stack);
}

Stack createStack(int length){
  Stack stack;
  stack.array = (int*)malloc(sizeof(int)*length);
  stack.head = 0;
  stack.length = length;
  return stack;
}

void push(Stack* stack, int x){
  if(stack->head >= stack->length){
    printf("The stack is full, you cannot push any element into it!\n");
  }else{
    stack->array[stack->head++] = x;
  }
}

int pop(Stack* stack){
  int result = -1;
  if(stack->head==0){
    printf("The stack is empty, you cannot pop any element from it!\n");
  }else{
    result = stack->array[stack->head-1];
    stack->head--;
  }
  return result;
}

int top(Stack stack){
  return stack.array[stack.head-1];
}

void traverse(Stack stack){
  int i;
  for(i=0;i<stack.head;i++){
    printf("%ld ", stack.array[i]);
  }
  printf("\n");
}
