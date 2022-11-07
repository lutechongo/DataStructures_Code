#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//BUBBLE SORT USING AN ARRAY
void bubbleSort(int * a, int n) {
int t, outer, inner;

    for(outer=0; outer<n; outer++) {
        for(inner=0; inner<n-1; inner++)
        {
            if (a[inner] > a[inner+1]) 
            {
                t = a[inner];
                a[inner] = a[inner+1];
                a[inner+1] = t;
            }
        }
    }
}

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
    printf("Unsorted Array = ");
    for (i=0; i<n; i++) 
    {
        printf(i?", %d":"%d", a[i]);
    }
    printf(".\n");
}

//main function
int main(int argc, char const *argv[]){
    int * a;                                            //pointer to array
    int n = 10;                                         //n represents how many elements we want our list to have

    srand(time(NULL));                                  //?

    a = createArray(n);                                 //a, our list, is being assigned the function that will create it
    printArray(a, n);

    bubbleSort(a, n);
    printf("Sorted from");
    printArray(a, n);

    free(a);
    return 0;
}