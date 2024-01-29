// linked list insert data
#include <stdio.h>
#include <stdlib.h>
struct Node{
    int data;
    struct Node *next;
};
int insertValueFirst(struct Node *head, int value){
    struct Node *temp = (struct Node*)calloc(1, sizeof(struct Node));
    temp->data = value;
    temp->next = head;
    
    head = temp;
    printData("First Item Add - ",head);
}
int insertValueLast(struct Node *head, int value){
    struct Node *current = head;
    while(current->next != NULL){
        current = current->next;
    }
    struct Node *temp = (struct Node*)calloc(1, sizeof(struct Node));
    temp->data = value;
    temp->next = NULL;
    
    current->next = temp;
    
    printData("Last Item Add - ",head);
}
// Add A Data in Middle of Linked List
int addDataMiddle(struct Node *head,int pos, int value){
    struct Node *current = head;
    struct Node *temp = (struct Node*)calloc(1, sizeof(struct Node));
    temp->data = value;
    temp->next = current->next;
    int counter = 0;
    while(current != NULL){
         counter++;
        if(counter == pos){
            temp->next = current->next;
             current->next=temp;
        }
        current = current->next;
    }
    printData("Middle Item adds - ",head);
}
int searchItem(struct Node *head, int value){
    int index = 1;
    while(head != NULL){
        if(head->data == value){
            return index;
        }
        index++;
        head = head->next;
    }
    return -1;
}
struct Node *printLinkedList(int arr[], int size){
    struct Node *head = NULL, *current = NULL, *temp= NULL;
    for(int i=0; i<size; i++){
        temp = (struct Node*)calloc(1, sizeof(struct Node));
        temp->data = arr[i];
        temp->next = NULL;
        
        if(head == NULL){
            head = temp;
            current = temp;
           
        }else{
            current->next = temp;
            current = current->next;
        }
    }
    
    return head;
}
void printData(const char *message, struct Node *head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node *current = head;
    while (current->next != NULL) {
        printf("%d ->", current->data);
        current = current->next;
    }
    printf("%d -> NULL\n", current->data);
}
int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int size = sizeof(arr) / sizeof(arr[0]);
    struct Node *head = NULL;
    head = printLinkedList(arr, size);
    printData("Original List -",head);  
    printf("Search Index - %d\n", searchItem(head, 40));
    insertValueFirst(head, 500);
    insertValueLast(head, 200);
    addDataMiddle(head, 2, 300);
     addDataMiddle(head, 4, 6000);
    printf("\n");

    return 0;
}
