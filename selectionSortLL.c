#include <stdio.h>
#include <stdlib.h>

struct node{
    int val;
    struct node *nxt;
};

struct node* start = NULL;

struct node* last = NULL;
struct node* temp;

struct node* createNode(int x)
{
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->val = x;
    newNode->nxt = NULL;
    return newNode;
}

void addLast(int y)
{
    struct node* hodor = createNode(y);
    if(start == NULL)
    {
        start = hodor;
        last = hodor;
    }
    else
    {
        last->nxt = hodor;
        last = hodor;
    }
}

void swap(struct node *x, struct node *y)
{
    int temp = x->val;
    x->val = y->val;
    y->val = temp;
}

/////////////////////////////////////////////
void printLL()
{
    temp = start;
    while(temp->nxt != NULL)
    {
        printf("%d\n", temp->val);
        temp = temp->nxt;
    }
    printf("%d\n", temp->val);
}
//////////////////////////////////////////////

void listSize(int size)
{
    int i, number;
    for( i = 0; i < size; i++ )
    {
        number = rand()%100;
        addLast(number);
    }
}
////////////////////////////////////////////////////////
 
void selectionLL()
{
    struct node* key;
    key = start;

    while(key != NULL)
    {
        temp = key->nxt;
        while(temp != NULL)
        {
            if(key->val > temp->val)
            {
                swap(key, temp);
            }
            temp = temp->nxt;
        }
        key = key->nxt;
    }
}
///////////////////////////////////////////////

int main()
{
    int choose;

    printf("Input list size: ");
    scanf("%d", &choose);
    listSize(choose);
    selectionLL();
    printLL();
    
}