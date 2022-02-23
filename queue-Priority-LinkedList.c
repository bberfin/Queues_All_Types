#include <stdio.h>
#include <stdlib.h>


typedef struct node { 
    int data; 
    int priority;      // Lower values indicate higher priority
    struct node* next; 
} Node; 


int is_empty(Node* head) { 
     if(head==NULL)
     return 1;
     else
     return 0;
} 


Node* new_node(int d, int p) { 
    Node* temp = (Node*)malloc(sizeof(Node)); 
    temp->data = d; 
    temp->priority = p; 
    temp->next = NULL; 
    return temp; 
} 

Node* push(Node* head, int d, int p) { 
    Node* start = head; 
    Node* temp = new_node(d, p);   // Create new Node 
  
    // Special Case: The head of list has lesser 
    // priority than new node. So insert new 
    // node before head node and change head node. 
     // Insert New Node before head 
    if (head->priority > p) { 
        temp->next = head; 
        (head) = temp; 
    } 
    else { 
        // Traverse the list and find a 
        // position to insert new node 
        while (start->next != NULL && start->next->priority < p) { 
            start = start->next; 
        } 
        // Either at the ends of the list 
        // or at required position 
        temp->next = start->next; 
        start->next = temp; 
    } 
    return head;
} 

Node* pop(Node* head) { 

    if(head==NULL){
    	printf("\nunderflow\n");
    	return ;
	}
    else{
   	Node* temp = head; 
    head = head->next; 
    free(temp); 
    return head;
	}
    
} 

int peek(Node* head) { 
    return (head)->data; 
} 

int main() {
	
	// Create a Priority Queue 
    // 7->4->5->6 
    Node* pq = new_node(4, 1); 
    pq=push(pq, 5, 2); 
    pq=push(pq, 6, 3); 
    pq=push(pq, 7, 0); 
  
    while (!is_empty(pq)) { 
        printf("%d ", peek(pq)); 
        pq=pop(pq); 
}
	return 0;
}
