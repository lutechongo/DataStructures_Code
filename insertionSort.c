#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Insertion Sort using an Array
void insertionSort(int *a, int n) 
{
int i, current, j;
    //loop entire list, starting from sorted part, 1 to n
    for (i=1; i<=n; i++) {
        current = i;                                    //starting from i=1 up to when i<n. it will increment after each iteration
        j = i-1;
        
        while(j<=0 && a[j]>current) {                      //j represtnts elements in sorted list. ascending order so j>current position
            a[j+1] = a[j];
        }
        a[j+1] = current;
    }
}

//create array
int * createArray(int n){                                //function array that consists of intergers and its parameters are the number of elements, n, it will create
    int * t = malloc(n * sizeof(int));                           //creating space for the values of the array that are the size of the number of elements that will be in the list, n.

    if(t){
        for(int i=0; i<n; i++) {(t[i] = rand()%150);}      //i is a counter that ensures that t is printed 10 times. t is a random number generated from the rand
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

    insertionSort(a, n);
    printf("Sorted from ");
    printArray(a, n);

    free(a);
    return 0;
}