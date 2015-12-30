#include <stdio.h>
#include <stdlib.h>
#include "basicio.h"
#include "algorithm.h"

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


int main(int argc, char *argv[]) {
    int *array; //[10] = {40, 32, 30, 39, 42, 23, 34, 39, 23, 43};
    int array_size; 
   
    if(argc < 2) {
        printf("Specify the data file name as an argument");
        return 0;
    }

    array_size = get_num_lines(argv[1]);
    array = (int *)malloc(sizeof(int)*array_size);
    
    read_data_from_file(argv[1], array, array_size);
    
    printarray(array, array_size);
    cocktailsort(array, array_size);
    printarray(array, array_size);
    return 0;
}
