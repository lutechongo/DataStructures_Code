#include <stdio.h>
#include <stdlib.h>

struct node 
{ 
    int val; 
    struct node *l, *r; 
}; 

//create a new Node
struct node* newNode(int item) 
{
    struct node* temp =  (struct node *)malloc(sizeof(struct node)); 
    temp->val = item; 
    temp->l = temp->r = NULL; 
    return temp; 
} 

//checking if a given node exists in a binary search tree or not
int search(struct node* root, int value) 
{ 
    // while is used to traverse till the end of tree
    while (root != NULL){

        if (value > root->val) 
            root = root->r; 
        else if (value < root->val) 
            root = root->l; 
        else
            return 1; // if the value is found return 1 
    } 
    return 0; 
} 

int main() 
{ 
    /*Root is created first*/
    struct node* root = newNode(21);
    root->l= newNode(16);
    root->r = newNode(25);
    root->l->l = newNode(10);
    root->l->r = newNode(18);
    root->r->l = newNode(22);
    root->r->r = newNode(28);
    root->l->l->l = newNode(8);
    root->l->l->r = newNode(12);

    int item = 10;

    // Function to find item in the tree
    int found = search(root,item);

    if(found)
        printf("%d value is found in the tree",item);
    else
        printf("%d value not found",item);

    return 0; 
} 