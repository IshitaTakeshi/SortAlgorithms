#include <stdio.h>
#include <stdlib.h>
#include "sortlib.h"

void shellsort(int array[], int array_size) {
    int inc = array_size/2;
    int i, j, tmp;

    while(inc > 0) {
        for(i=inc; i<array_size; i++) {
            j = i;
            tmp = array[i];
            while(j >= inc && array[j-inc] > tmp) {
                array[j] = array[j-inc];
                j -= inc;
            }
            array[j] = tmp;
        }

        if (inc == 2) {
            inc = 1;
        } else {
            inc *= (5.0 / 11);
        }
    }
}
