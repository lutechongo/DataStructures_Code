#include <stdio.h>
#include <stdlib.h>
 
// A Linked List Node
struct Node
{
    int data;
    struct Node* next_node;
};
 
//Printing linked list
void printList(struct Node* head)
{
    struct Node* ptr = head;
    while (ptr)
    {
        printf(head?" %d":"%d", ptr->data);
        ptr = ptr->next_node;
    }
 
    printf("NULL\n");
}
 
// Helper function to insert a new node at the beginning of the linked list
void createdLinked(struct Node** head, int data)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next_node = *head;
 
    *head = newNode;
}
 

struct Node* chunkReverseK(struct Node** current_ptr, int k)
{
    struct Node* previous_ptr = NULL;
    int count = 0;
 
    // iterate through the list and move/insert each node
    // in front of the result list (like a push of the node)
    while (*current_ptr && count++ < k)
    {
        // tricky: note the next node
        struct Node* next_node = (*current_ptr)->next_node;
 
        // move the current node onto the result
        (*current_ptr)->next_node = previous_ptr;
 
        // update the previous pointer to the current node
        previous_ptr = *current_ptr;
 
        // move to the next node in the list
        *current_ptr = next_node;
    }
 
    // return last processed node
    return previous_ptr;
}
 
// Function to reverse every group of `k` nodes in a given linked list
struct Node *chunkReverse(struct Node *head, int k)
{
    // base case
    if (head == NULL) {
        return NULL;
    }
 
    // start with the current node
    struct Node* current_ptr = head;
 
    // reverse next `k` nodes
    struct Node* previous_ptr = chunkReverseK(&current_ptr, k);
 
    // recur for remaining nodes
    head->next_node = chunkReverse(current_ptr, k);
 
    // it is important to return the previous node (to link every group of `k` nodes)
    return previous_ptr;
}
 
int main(void)
{
    // input keys
    int keys[] = { 1, 2, 3, 4, 5, 6, 7, 8 };
    int n = sizeof(keys)/sizeof(keys[0]);
 
    struct Node* head = NULL;
    for (int i = n - 1; i >=0; i--) {
        push(&head, keys[i]);
    }
 
    head = chunkReverse(head, 2);
 
    printList(head);
 
    return 0;
}