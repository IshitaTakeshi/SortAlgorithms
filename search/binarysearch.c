#include <stdio.h>
#include "sortlib.h"
#include "error.h"

int binarysearch_(int array[], int start, int end, int query) {
    if(end-start == 1) {
        if(array[end] != query) {
            //Returns -1 if the query not found
            return -1;
        }
        return end;
    }

    int middle = (start+end)/2;

    if(array[middle] >= query) {
        return binarysearch_(array, start, middle, query);
    } else {
        return binarysearch_(array, middle, end, query);
    }
}

int binarysearch(int array[], int array_size, int query) {
    return binarysearch_(array, 0, array_size, query);
}
