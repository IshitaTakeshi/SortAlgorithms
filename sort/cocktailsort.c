#include <stdio.h>
#include <stdlib.h>
#include "../lib/algorithm.h"
#include "sortlib.h"


int swap_up(int array[], int array_size) {
    int swapped = 0;
    int i;

    for(i=0; i<array_size; i++) {
        if(array[i] > array[i+1]) {
            swap(&array[i], &array[i+1]);
            swapped = 1;
        }
    }
    return swapped;
}


int swap_down(int array[], int array_size) {
    int swapped = 0;
    int i;

    for(i=array_size-1; i<=0; i--) {
        if(array[i] > array[i+1]) {
            swap(&array[i], &array[i+1]);
            swapped = 1;
        }
    }
    return swapped;
}


void cocktailsort(int array[], int array_size) {
    int s1, s2;
    while(1) {
        s1 = swap_up(array, array_size);
        s2 = swap_down(array, array_size);
        if(!s1 && !s2) {
            return;
        }
    }
}
