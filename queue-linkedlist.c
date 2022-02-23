#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *next;
};

struct queue{
	struct node *front;
	struct node *rear;
};

	 

struct queue *create_queue(){
	struct queue* q = (struct queue*)malloc(sizeof(struct queue)); 
    q->front = q->rear = NULL; 
    return q; 	
}

struct queue *insert(struct queue *que, int val){
	
	struct node *ptr;
	ptr = (struct node*)malloc(sizeof(struct node));
	ptr->data=val;
	
	if(que->front==NULL){
		que->front=ptr;
		que->rear=ptr;
		que->front->next=que->rear->next=NULL;		
	}
	
	else{
	    que->rear->next=ptr;
		que->rear=ptr;
		que->rear->next=NULL;
	}
	
	return que;
}

void display(struct queue *que){
	struct node *ptr;
	ptr=que->front;
	
	if(ptr==NULL)
	printf("\nqueue is empty\n");
	else{
		while(ptr!=que->rear){
			printf("%d ",ptr->data);
			ptr=ptr->next;
		}
		printf("%d\n",ptr->data);
	}
   
}


struct queue *delete_element(struct queue *que){
	struct node *ptr;
	ptr=que->front;
	
	if(que->front == NULL)
	printf("\nunderflow");
	else{
		que->front = que->front->next;
		printf("\nthe value being deleted is : %d\n",ptr->data);
		free(ptr);
	}
	return que;
}

int peek(struct queue *que){
	if(que->front == NULL){
		printf("\nunderflow");
		return -1;
	}
	else
	return que->front->data;

}

int main() {
	
     struct queue *que;
     que=create_queue();
     
	 int i;
	 for(i=1;i<=10;i++)
	 que=insert(que,i);
	 
     display(que);
	 printf("the top value is : %d\n",peek(que));
     
     que=delete_element(que);
	 display(que);
	 
	 printf("the top value is : %d\n",peek(que));
	
	
	que=delete_element(que);
	 display(que);
	 
	 printf("the top value is : %d\n",peek(que));
	
	
	
	
	
	
	
	return 0;
}
