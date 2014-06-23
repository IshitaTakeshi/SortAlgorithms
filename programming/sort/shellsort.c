#include <stdio.h>
#include <stdlib.h>
#include "basicio.h"

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

int main(int argc, char *argv[]) {
    int *array; 
    int array_size; 
     
    array_size = get_num_lines(argv[1]);
    array = (int *)malloc(sizeof(int)*array_size);
    read_data_from_file(argv[1], array, array_size);
    
    printarray(array, array_size);
    shellsort(array, array_size);
    printarray(array, array_size);
    return 0;
}
