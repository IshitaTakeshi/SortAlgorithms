#include <stdio.h>
#include "algorithm.h"

void bubblesort(int array[], int N) {
    int i, j, t; 

    for(i=N-1; i>0; i--) {
        for(j=0; j<i; j++) {
            if(array[j] >= array[j+1]) {
                swap(&array[j], &array[j+1]);
            }
        }
    } 
}

int main(void) {
    int i, N;
    int array[10];// = {20, 32, 320, 39, 423, 232, 342, 320, 230, 432};
    int result[10];
   
    N = sizeof(array)/sizeof(int); 
    
    read_digits(array, N);
    bubblesort(array, N);
    printarray(array, N);

    return 0;
}
