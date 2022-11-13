#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Quick Sort using an array
void swap (int * x, int * y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

int partition (int * a, int start, int stop) {        //puts an element in its correct position. everthing on left and right of it is lesser and greater respectively
    int pivot = a[stop];
    int i = start - 1; 
    int j;                               //position right next to start. everything on left of i is less than pivot.                                     //last position. everything to the right of j is greater than pivot

    for (j = start; j < stop; j++){
        if (a[j] <= pivot) {
            i++;
            swap(&a[i], &a[j]);
        }
    }
    swap(&a[i + 1], &a[stop]);

    return( i + 1);
}
    /*while (i <= j) {
        if (a[i] > pivot) {
           i = i+1;}
            
        else (swap(&a[start], &a[i]));
    return pivot;
}
                                        //gives the correct position of j

};*/

void quickSort(int * a, int start, int stop) {
    if (start < stop) {

        int pivot = partition(a, start, stop);          //gives us a list with en elemnt in its right postion. less than stuff on right. greater than stuff is greater
        quickSort(a, start, pivot - 1);                   //partitions the left side
        quickSort(a, pivot + 1, stop);                    //partitions the right side
    }
}

/*void quicksort(int * a, int n) {
    quickSort(a, 0, n-1);
}*/

//create array
int * createArray(int n){                                //function array that consists of intergers and its parameters are the number of elements, n, it will create
    int * t = malloc(n * sizeof(int));                   //creating space for the values of the array that are the size of the number of elements that will be in the list, n.

    if(t){
        for(int i=0; i<n; i++) {(t[i] = rand()%150);}    //i is a counter that ensures that t is printed 10 times. t is a random number generated from the rand
    }
    return t;               
};

//print array
void printArray(int * a, int n) {
    printf("Unsorted =");
    for (int i = 0; i < n; i++) 
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

    quickSort(a, 0, n - 1);
    printf("Sorted = ");
    printArray(a, n);

    free(a);
    return 0;
}