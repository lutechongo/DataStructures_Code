#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//swap elements
void swap(int * x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

//create minimum heap
void min_heapify (int * a, int n, int i) {
    //declare root variables and left and right branch variables   
    int smallest = i;
    int left_child = 2*i+1;
    int right_child = 2*i+2;

    if (left_child < n && a[left_child] < a[smallest]) {
        smallest = left_child;
    }

    if (right_child < n && a[right_child] < a[smallest]) {
        smallest = right_child;
    }

    if (smallest!=i) {
        swap(&a[i], &a[smallest]);
        min_heapify(a, n, smallest);
    }
}

//print heap
void buildHeap (int * a, int n){
    int lasatLeafNode = (n-2) -1;

    for (int i=lasatLeafNode; i>=0;i--){
        min_heapify(a,n,i);
    }
}

//delete
void delete(int * array, int n, int i)
{
    int input = i;

    for (i = 0; i < n; i++)
    {
        if (input == array[i])
        break;
    }

    swap(&array[i], &array[n - 1]);
    n -= 1;

    for (int i = n / 2 - 1; i >= 0; i--)
    {
        min_heapify(array, n, i);
    }
}
//create array
int * createArray(int n){                                        //function array that consists of intergers and its parameters are the number of elements, n, it will create
    int * t = malloc(n * sizeof(int));                           //creating space for the values of the array that are the size of the number of elements that will be in the list, n.

    if(t){
        for(int i=0; i<n; i++) {(t[i] = rand()%50);}             //i is a counter that ensures that t is printed 10 times. t is a random number generated from the rand
    }
    return t;              
}

//print array
void printArray(int * a, int n) {
    int i;
    printf("Array = ");
    for (i=0; i<n; i++) 
    {
        printf(i?", %d":"%d", a[i]);
    }
    printf(".\n");
}

int main(){
    int i;
    int * a;
    int n = 7;

    srand(time(NULL));                              

    a = createArray(n);                                 //a, our list, is being assigned the function that will create it
    printArray(a, n);

    delete(a, n, 1);
    printf("New ");
    printArray(a, n);
}