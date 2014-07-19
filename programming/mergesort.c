#include <stdio.h>
#include <stdlib.h>
#include "algorithm.h"
#include "sortlib.h"

void merge(int array[], int left_start, int left_end, 
           int right_start, int right_end) {
    int left_index;
    int right_index;
    int result_index = 0;
    int left_size = left_end - left_start;
    int right_size = right_end - right_start;
    int left[left_size];
    int right[right_size];
    int i;
    
    left_index = 0;
    i = left_start;
    while(i < left_end) {
        left[left_index] = array[i];
        i += 1;
        left_index += 1;
    }
    
    right_index = 0;
    i = right_start;
    while(i < right_end) {
        right[right_index] = array[i];
        i += 1;
        right_index += 1;
    }

    i = left_start;
    right_index = 0; 
    left_index = 0; 
    while(left_index < left_size && right_index < right_size) {
        if(left[left_index] < right[right_index]) { 
            array[i] = left[left_index]; 
            left_index += 1;
        } else { 
            array[i] = right[right_index]; 
            right_index += 1;
        }
        i++;
    }
     
    while(left_index < left_size) {
        array[i] = left[left_index];
        i += 1;
        left_index += 1;
    }

    while(right_index < right_size) {
        array[i] = right[right_index];
        i += 1;
        right_index += 1;
    } 
}

void mergesort_(int array[], int left, int right) {
    if(right-left <= 1) {
        return;
    }
    
    //printf("here"); 
    int middle = (left+right)/2;
    int result[right-left-1];
    //printf("left:%d right:%d middle:%d\n", left, right, middle);
    mergesort_(array, left, middle);
    mergesort_(array, middle, right);
    merge(array, left, middle, middle, right);
}

void mergesort(int array[], int array_size) {
    mergesort_(array, 0, array_size);
}
