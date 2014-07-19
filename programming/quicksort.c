#include <stdio.h>
#include <stdlib.h>
#include "algorithm.h"
#include "sortlib.h"


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
