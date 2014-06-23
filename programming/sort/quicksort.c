#include <stdio.h>
#include <stdlib.h>
#include "basicio.h"
#include "algorithm.h"

void quicksort(int array[], int array_size) {
    if(array_size <= 1) {
        return;
    }

    int pivot = array[array_size/2];
    int *left = array;
    int *right = array+array_size-1; //the address of the last element of the array

    while(left <= right) {
        if(*left < pivot) {
            left += 1;
            continue;
        }
        
        if(*right > pivot) {
            right -= 1;
            continue;
        }
        
        swap(left, right);    
        
        left++;
        right--;
    }

    quicksort(array, right-array+1);
    quicksort(left, array+array_size-left);
}

int main(int argc, char *argv[]) {
    
    int *array; 
    int array_size; 
     
    array_size = get_num_lines(argv[1]);
    array = (int *)malloc(sizeof(int)*array_size);
    
    read_data_from_file(argv[1], array, array_size);

    printarray(array, array_size);
    quicksort(array, array_size);  
    //write_data_to_file(argv[2], array, array_size);
    printarray(array, array_size);
    return 0;
}
