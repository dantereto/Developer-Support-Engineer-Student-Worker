#include <stdio.h>  
#include <stdlib.h>  

struct node{  
    int data;  
    struct node *previous;  
    struct node *next;  
};      
   
struct node *head, *tail = NULL;  
   
void addNode(int data) {  

    struct node *newNode = (struct node*)malloc(sizeof(struct node));  
    newNode->data = data;  
    
    if(head == NULL) {  
        head = tail = newNode;  
        head->previous = NULL;  
        tail->next = NULL;  
    }  
    else {  
        tail->next = newNode;  
        newNode->previous = tail;  
        tail = newNode;  
        tail->next = NULL;  
    }  
}  

/* display() will print out the nodes of the list  */
void display() {  
    /* Node current will point to head  */ 
    struct node *current = head;  
    if(head == NULL) {  
        printf("List is empty\n");  
        return;  
    }  
    printf("Nodes of doubly linked list: \n");  
    while(current != NULL) {   
        /* Prints each node by incrementing pointer. */ 
        printf("%d \n", current->data);  
        /* points to the next node in the list */ 
        current = current->next;  
    }  
}  

int main()  
{  
    addNode(1);  
    addNode(2);  
    addNode(3);  
    addNode(4);  
    addNode(5);  
    
    display();  
   
    return 0;  
}  