#include <stdio.h>
#include <stdlib.h>
#include "basicio.h"
#include "algorithm.h"

void slide_to_right(int array[], int start, int end) {
    int k, tmp;
    tmp = array[end];
    for(k=end; k>start; k--) {
        array[k] = array[k-1];
    }
    array[start] = tmp;
}


void insertionsort(int array[], int N) {
    int i, j;
    
    if(array[0] > array[1]) {
        swap(&array[0], &array[1]);
    }

    for(i=2; i<N; i++) {
        for(j=0; j<i; j++) {
            if(array[j] > array[i]) {
                slide_to_right(array, j, i);
            }
        }
    }
}


void work2(void) {
    int i, N;  
    int array[10]; //= {40, 32, 30, 39, 42, 23, 34, 39, 23, 43};

    N = sizeof(array)/sizeof(int);

    //insertionsort(array, N);

    read_digits(array, N);
    printarray(array, N);
    insertionsort(array, N);
    printarray(array, N);
}


void work3(char filename[]) {
    int *array; 
    int array_size; 
   
    array_size = get_num_lines(filename);
    array = (int *)malloc(sizeof(int)*array_size);
    
    read_data_from_file(filename, array, array_size);
    
    printarray(array, array_size);
    printarray(array, array_size);
}


int main(int argc, char *argv[]) {
    int *array; //[10] = {40, 32, 30, 39, 42, 23, 34, 39, 23, 43};
    int array_size; 
   
    if(argc < 2) {
        printf("Specify the data file name as an argument");
        return 0;
    }
    work2(); 
    work3(argv[1]);    
    return 0;
}
