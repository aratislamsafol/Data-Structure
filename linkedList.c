// create a linked list from an array
#include <stdio.h>
#include <stdlib.h>
struct Node{
    int data;
    struct Node *next;
};
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
struct Node *createLinkedList(int arr[] ,int size){
    struct Node *head = NULL, *temp = NULL, *current = NULL;
    for(int i=0; i<size; i++){
         // Dynamic Memory Allocation
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
};
int main() {
   int arr[] = {10, 20, 30, 40, 50}; 
    struct Node *head = createLinkedList(arr, sizeof(arr)/sizeof(arr[0]));
    printf("Search Index - %d\n", searchItem(head, 40));
    
    while( head != NULL){
        printf("%d ->",head->data);
        // here head = head->next ==== head ++
        head = head->next;
    }
    printf("\n");
   

    return 0;
}