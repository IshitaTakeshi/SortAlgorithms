#include <stdio.h>
#include "algorithm.h"
#include "sortlib.h"

void bubblesort(int array[], int array_size) {
    int i, j, t; 

    for(i=array_size-1; i>0; i--) {
        for(j=0; j<i; j++) {
            if(array[j] >= array[j+1]) {
                swap(&array[j], &array[j+1]);
            }
        }
    } 
}
