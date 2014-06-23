#include <stdio.h>
#include "basicio.h"
#include "algorithm.h"

void selectionsort(int* array, int N) {
    int i, j, min, tmp, minposition;

    for(i=0; i<N; i++) {
        minposition = i;
        for(j=i+1; j<N; j++) {
            if(array[j] < array[minposition]) {
                minposition = j;
            }
        }
        
        swap(&array[i], &array[minposition]);
    }
}

int main(void) {
    int array[10];
    int N;

    N = sizeof(array)/sizeof(int); 
    
    read_digits(array, N);
    selectionsort(array, N);
    printarray(array, N);
}
