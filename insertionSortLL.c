#include <stdio.h>
#include <stdlib.h>
 
struct node {
    int element;
    struct node* next;
};
 
struct node* head = NULL;
struct node* sorted = NULL;
 
void push(int val)
{
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->element = val;
    newnode->next = head;
    head = newnode;
}

//SORTED Part
void sortedInsert(struct node* newnode)
{
    if (sorted == NULL || sorted->element >= newnode->element) {
        newnode->next = sorted;
        sorted = newnode;
    }
    else {
        struct node* current = sorted;

        while (current->next != NULL
               && current->next->element < newnode->element) {
            current = current->next;
        }
        newnode->next = current->next;
        current->next = newnode;
    }
}
 
// Sorting linked list
void insertionsort()
{
    struct node* current = head;
    while (current != NULL) {
        struct node* next = current->next;
        sortedInsert(current);

        current = next;
    }
    head = sorted;
}
 
/////Print linked list 
void printlist(struct node* head)
{
    while (head != NULL) {
        printf("%d->", head->element);
        head = head->next;
    }
    printf("NULL");
}
 
////////////////////////////////////////////////
int main()
{
 
    push(2);
    push(25);
    push(41);
    push(13);
    push(370);
 
    printf("Before sorting:\n");
    printlist(head);
    printf("\n");
 
    insertionsort(head);
 
    printf("After sorting:\n");
    printlist(head);
}