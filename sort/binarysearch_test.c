#include <stdlib.h>
#include <stdio.h>
#include "sortlib.h"
#include "searchlib.h"
#include "basicio.h"

int search_test(int array[], int array_size, int query) {
    int index = binarysearch(array, array_size, query);
    if(index < 0) {
        printf("%d is not found\n", query);
        return index;
    }
    printf("%d is found at line %d\n", query, index);
    return 0;
}

int main(int argc, char *argv[]) {
    int *array;
    int array_size;
    int query; 

    if(argc < 2) {
        printf("Specify the data file name as an argument");
        return 0;
    }

    array_size = get_num_lines(argv[1]);
    array = (int *)malloc(sizeof(int)*array_size);
    
    read_data_from_file(argv[1], array, array_size);
    
    quicksort(array, array_size);

    search_test(array, array_size, 644104147);
    search_test(array, array_size, 816070184);
    search_test(array, array_size, 454691142);

    free(array);
    return 0;
}
