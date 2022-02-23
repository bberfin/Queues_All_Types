#include <stdio.h>
#include <stdlib.h>
#define QUEUE_SIZE 7


typedef struct{
	int front,rear;
	int data[QUEUE_SIZE];
}queue_t;


void initialize(queue_t *q){
	q->front=-1;
	q->rear=-1;
}

int is_empty(queue_t *q){
    if((q->front == -1))
    return 1;
    return 0;

}


int is_full(queue_t *q){
	if((q->front > q->rear ) || (q->front == 0 && q->rear == QUEUE_SIZE-1))
	return 1;
	return 0;
}


void insert(queue_t *q,int item){
	
    if((q->rear+1)%QUEUE_SIZE == q->front)
    printf("..Queue is FULL!..(overflow)\n");
    
    else if (q->front == -1 && q->rear==-1){
    	q->front=q->rear=0;
    	q->data[q->rear]=item;
	}
    
    else if(q->rear==QUEUE_SIZE-1 && q->front!=0)	{
    		q->rear=0;
    		q->data[q->rear]=item;
	}
    
    else{
    	q->rear++;
    	q->data[q->rear]=item;
	}
	
}

void display(queue_t* q){
	int i;
	if(is_empty(q))
	printf("..Queue is EMPTY!..(underflow)\n");
	else{
		printf("\n Front -> %d ", q->front);
        printf("\n Items -> ");
		for(i=q->front;i!=q->rear;i=(i+1)%QUEUE_SIZE)
		printf("%d ",q->data[i]);
		
		printf("%d ", q->data[i]);
        printf("\n Rear -> %d \n", q->rear);
	}
	
}


int delete_element(queue_t *q){
	int val;
	if(q->front==-1 && q->rear==-1){
		printf("\n..underflow..\n");
		return -1;		
	}
	val=q->data[q->front];
	
	if(q->front==q->rear)
	q->front=q->rear=-1;
	else
	{
		if(q->front==QUEUE_SIZE-1)
		q->front=0;
		else
		q->front++;
	}
	
return val;
}


int main() {
	queue_t que;
	 int i,n;
	 initialize(&que);
	 for(i=1;i<=7;i++)
	 insert(&que,i);
     display(&que);
     
     for(i=1;i<=3;i++)
     delete_element(&que);
     
     display(&que);
     
     for(i=1;i<=3;i++)
	 insert(&que,i);
	 
	 display(&que);
	 
	return 0;
}
