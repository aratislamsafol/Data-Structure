// Doubly Linked List
#include <stdio.h>
#include <stdlib.h>
// create a structure of node for doubly linked list
struct Node{
    struct Node *prev;
    int data;
    struct Node *next;
};
// create a add node in doubly linked list
struct Node *addNode(struct Node *head, int data, int addToEnd){
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->next = NULL;
    temp->data= data;
    temp->prev = NULL;
    if(head == NULL){
        head = temp;
    }else{
        if(addToEnd){
            struct Node *ptr = head;
            while (ptr->next != NULL) {
                ptr = ptr->next;
            }
            ptr->next= temp;
            temp->prev = ptr;
        }else{
            temp->next = head;
            head->prev = temp;
            head = temp;
        }
    }
    return head;
}

int main() {
    struct Node *head = NULL;
    struct Node *ptr;
    head = addNode(head, 45,0);
    head = addNode(head, 35,0);
    head = addNode(head, 25,1);
    head = addNode(head, 15,0);
    head = addNode(head, 5,1);
    ptr= head;
    while(ptr != NULL){
         printf("%d->", ptr->data);
         ptr = ptr->next;
    }
   
    return 0;
}