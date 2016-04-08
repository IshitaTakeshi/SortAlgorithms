#include <stdio.h>


int binarysearch_(int array[], int start, int end, int key) {
    if(start > end) {
        return -1;
    }

    int middle = start+(end-start)/2;

    if(key < array[middle]) {
        return binarysearch_(array, start, middle-1, key);
    } else if(key > array[middle]) {
        return binarysearch_(array, middle+1, end, key);
    } else {
        return middle;
    }
}


int binarysearch(int array[], int array_size, int key) {
    return binarysearch_(array, 0, array_size, key);
}
