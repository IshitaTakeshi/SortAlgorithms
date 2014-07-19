#include <stdio.h>
#include <stdlib.h>
#include "sortlib.h"


void swap_array_elements(int array[], int a, int b) {
    int tmp;
    tmp = array[a];
    array[a] = array[b];
    array[b] = tmp;
}

void shiftdown(int array[], int start, int end) {
    int root, child;

    root = start;
    while(1) {
        child = root*2+1;
        if(child > end) {
            return;
        }
        if(child+1 <= end && array[child] < array[child + 1]) {
            child += 1;
        }
        if(array[child] > array[root]) {
            swap_array_elements(array, root, child);
            root = child;
        } else {
            return;
        }
    }
}

void heapsort(int array[], int array_size) {
    int start, end;

    for(start=array_size/2-1; start>=0; start--) {
        shiftdown(array, start, array_size-1);
    }

    for(end=array_size-1; end>=1; end--) {
        swap_array_elements(array, 0, end);
        shiftdown(array, 0, end-1);
    }
}
