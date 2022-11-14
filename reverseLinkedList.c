#include<stdio.h>
#include<stdlib.h>

struct node  //code for making a node
{
    int value;
    struct node *next_addrs;
};

void print_nodes(struct node *head) 
{
    if (head == NULL) 
       return; 
  
    //print the list after head node 
    print_nodes(head -> next_addrs); 
  
    //print everything then print head 
    print_nodes("%d", head -> value); 
}


int main()
{
    struct node *before,*head, *q;

    int n,i;

    printf ("Size of Linked List? : ");

    scanf("%d",&n);

    head = NULL;

    for(i = 0; i < n; i++) { q = malloc(sizeof(struct node)); printf ("Enter a value: "); scanf("%d",&q -> value);
        q -> next_addrs = NULL;
        if(head == NULL)
            head = q;
        else
            before -> next_addrs = q;
        before = q;
    }
    print_nodes(head);
    return 0;
}