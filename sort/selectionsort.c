#include <stdio.h>
#include "../lib/algorithm.h"
#include "../lib/basicio.h"


void selectionsort(int array[], int array_size) {
    int i, j, min, tmp, minposition;

    for(i=0; i<array_size; i++) {
        minposition = i;
        for(j=i+1; j<array_size; j++) {
            if(array[j] < array[minposition]) {
                minposition = j;
            }
        }

        swap(&array[i], &array[minposition]);
    }
}
