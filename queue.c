#include <stdio.h>
#include <stdlib.h>

typedef struct Queue{
  int* array;
  int front;
  int rear;
  int count;
  int length;
}Queue;

Queue createQueue(int length);
void enqueue(Queue* queue, int x);
int dequeue(Queue* queue);
int top(Queue queue);
void traverse(Queue queue);

int main(){
  int length;
  printf("please input the lentgh of the queue:");
  scanf("%ld",&length);
  Queue queue = createQueue(length);
  enqueue(&queue,5);
  traverse(queue);
  enqueue(&queue,10);
  traverse(queue);
  enqueue(&queue,15);
  traverse(queue);
  enqueue(&queue,3);
  traverse(queue);
  printf("%ld\n",dequeue(&queue));
  traverse(queue);
  printf("%ld\n", top(queue));
  traverse(queue);
}

Queue createQueue(int length){
  Queue queue;
  queue.array = (int*)malloc(sizeof(int)*length);
  queue.front = 0;
  queue.rear = 0;
  queue.count = 0;
  queue.length = length;
  return queue;
}

void enqueue(Queue* queue, int x){
  if(queue->count >= queue->length){
    printf("The queue is full, you cannot enqueue any element into it!\n");
  }else{
    queue->array[queue->rear] = x;
    if(queue->rear == queue->length-1){//to deal with the boundary problem in circular queue.
      queue->rear = 0;
    }else{
      queue->rear++;
    }
    queue->count++;
  }
}

int dequeue(Queue* queue){
  int result = -1;
  if(queue->count==0){
    printf("The queue is empty, you cannot dequeue any element from it!\n");
  }else{
    result = queue->array[queue->front];
    if(queue->front == queue->length-1){//to deal with the boundary problem in circular queue.
      queue->front = 0;
    }else{
      queue->front++;
    }
    queue->count--;
  }
  return result;
}

int top(Queue queue){
  return queue.array[queue.front];
}

void traverse(Queue queue){
  if(queue.count != 0){
    int i = queue.rear;
    do{
      printf("%ld ",queue.array[i]);
      if(i == queue.length-1){
	i = 0;
      }else{
	i++;
      }
    }while(i != queue.rear);
    printf("\n");
  }
}
