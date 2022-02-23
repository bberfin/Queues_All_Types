#include <stdio.h>
#include <stdlib.h>
#define QUEUE_SIZE 10



typedef struct{
	int front,rear;
	int data[QUEUE_SIZE];
}queue_t;


void initialize(queue_t *q){
	q->front=0;
	q->rear=-1;
}



int is_empty(queue_t *q){
    if( (q->front > q->rear) || (q->front == -1))
    return 1;
    return 0;

}


int is_full(queue_t *q){
	if(q->rear == QUEUE_SIZE-1)
	return 1;
	return 0;
}


void insert(queue_t *q,int item){
	if(is_full(q))
	printf("Error..Queue is FULL!..(overflow)");
	else if (q->front == q->rear == -1)
	q->front = q->rear = -1;
	else{
		(q->rear)++;
		q->data[q->rear]=item;	
	}
}


int remove_q(queue_t *q){
	int item;
	if(is_empty(q))
	printf("Error..Queue is EMPTY!..(underflow)");
	else{
	item=q->data[q->front];
	(q->front)++;
	}
   	return item;
}


int peek(queue_t *q){
	if(is_empty(q))
	printf("Error..Queue is EMPTY!..(underflow)");
	else
	return q->data[q->front];
	
}

void display(queue_t* q){
	int i;
	if(is_empty(q))
	printf("Error..Queue is EMPTY!..(underflow)");
	else{
		for(i=q->front;i<=q->rear;i++)
		printf("%d ",q->data[i]);
	}
	
}

int main() {
	
	 queue_t que;
	 int i,n;
	 initialize(&que);
	 for(i=1;i<=10;i++)
	 insert(&que,i);
     display(&que);
	 
	
	return 0;
}
