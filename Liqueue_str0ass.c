#include<stdio.h>
#include<stdlib.h>


typedef struct queue{
   int *arr;
   int SIZE;
   int front,rear;
}queue_t;

void init_queue(queue_t *q, int size){
q->SIZE = size;
q->arr = (int *)malloc(sizeof(int) * size);
q->front = q->rear = 0;

}

void push(queue_t *q, int value){

    if(q->rear == q->SIZE -1)
    printf("Queue is full\n");

    else{

    //repos rear
     q->rear ++;
    //add value rear index
    q->arr[q->rear] = value;
}
}

int pop(queue_t *q){
    int temp = 0;
if(q->front == q->rear)
    printf("Queue is Empty\n");
else{
//repos front++
temp = q->arr[q->front +1];
q->front = q->rear = 0;
}
 return temp;
}

int peek(queue_t *q){
    int temp = 0;
if(q->front == q->rear)
    printf("Queue is Empty\n");
else{
//repos front++
temp = q->arr[q->front +1];
q->front++;

if(q->front == q->rear)
q->front = q->rear = 0;
}
 return temp;
}

int is_Empty(queue_t *q){
    return q->front == q->rear;
}

int is_Full(queue_t *q){
    return q->rear == q->SIZE - 1;
}

int main(){
 queue_t q;
 int size,value , choice;

 printf("Enter the size\n");
 scanf("%d",&size);

 init_queue(&q,size);
 do
 {
    printf("1. push/n 2. pop/n 3.peek/n");
    printf("Enter the choice\n");
 scanf("%d",&choice);
switch (choice)
{
case 1:
          printf("Enter the value\n");
          scanf("%d",&value);
           push(&q,value);
    break;
case 2: 
        printf("pop data is %d\n",pop(&q));
        break;
case 3:
        printf("peek data is %d\n",peek(&q) );    
}

} while (choice != 0);
 

free(q.arr);

    return 0;
}