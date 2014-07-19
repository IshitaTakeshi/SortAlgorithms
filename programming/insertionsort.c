#include <stdio.h>
#include <stdlib.h>
#include "algorithm.h"
#include "sortlib.h"

void slide_to_right(int array[], int start, int end) {
    int k, tmp;
    tmp = array[end];
    for(k=end; k>start; k--) {
        array[k] = array[k-1];
    }
    array[start] = tmp;
}


void insertionsort(int array[], int array_size) {
    int i, j;
    
    if(array[0] > array[1]) {
        swap(&array[0], &array[1]);
    }

    for(i=2; i<array_size; i++) {
        for(j=0; j<i; j++) {
            if(array[j] > array[i]) {
                slide_to_right(array, j, i);
            }
        }
    }
}
