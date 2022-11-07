#include <stdio.h>
#include <stdlib.h>

//Loop stress test

int main(int argc, char** argv){

    float a;
    float increment = 0.0000000000001; //Change around this
    float n = 0.0000000001; //And this (this is 10 times increment)
    int counter = 1;

    for (a=0.0; a<n; a+=increment) {
        printf("%d\n", counter);
        counter++;
    }

    return 0;
}