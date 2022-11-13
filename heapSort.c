#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//swap elements
void swap(int * x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

//####################################################################################

void maxHeapify (int * a, int n, int i) {
    //declare root variables and left and right branch variables   
    int biggest = i;
    int left_child = 2*i+1;                 
    int right_child = 2*i+2;

    //if left child is greater then set biggest to left child, biggest = 2*i+1
    if (left_child <= n && a[left_child] > a[biggest]) {
        biggest = left_child;
    }

    //if right child is greater then set biggest to right child, biggest = 2*i+2
    if (right_child <= n && a[right_child] > a[biggest]) {
        biggest = right_child;
    }

    //if root is not biggest, swap current i with biggest
    if (biggest!=i) {                                                                   
        //biggest has been updated
        swap(&a[i], &a[biggest]);
    
        maxHeapify(a, n, biggest);
    }
}

//####################################################################################

void heapSort(int * a, int n) {
    //make sure heap is a max heap
    //swap root with last element
    //delete the last element (former root of the heap - biggest element)
    //heapify the current heap from current root(previous last element) to second last element
    //last element(biggest number - former root) is in the correct position
    for (int i = (n / 2); i >= 0; i--){
        maxHeapify(a, n, i);

        for (int i = n-1; i>=0;i--) {
            swap(&a[0], &a[i]);
            maxHeapify(a, i, 0);            //max heapify 6 elements from total 7 (last element is already sorted) starting from the 0 (root)
        }
    }

}

//####################################################################################

//print heap
void buildHeap (int * a, int n){
    int begin = (n-2)-1;

    for (int i = begin; i >= 0;i--){
        maxHeapify(a, n ,i);
    }
}

//####################################################################################

//create array
int * createArray(int n){                                //function array that consists of intergers and its parameters are the number of elements, n, it will create
    int * t = malloc(n * sizeof(int));                           //creating space for the values of the array that are the size of the number of elements that will be in the list, n.

    if(t){
        for(int i=0; i<n; i++) {(t[i] = rand()%50);}      //i is a counter that ensures that t is printed 10 times. t is a random number generated from the rand
    }
    return t;              
}

//print array
void printArray(int * a, int n) {
    int i;
    for (i=0; i<n; i++) 
    {
        printf(i?", %d":"%d", a[i]);
    }
    printf("\n");
}

//####################################################################################

int main(){
    int * a;
    int n = 7;

    srand(time(NULL));                                  

    a = createArray(n);                                //a, our list, is being assigned the function that will create it
    printf("Unsorted = ");
    printArray(a, n);

    heapSort(a, n);
    printf("Sorted = ");
    printArray(a, n);
} 