#include <stdio.h>
#include <stdlib.h>
#include "../sort/sortlib.h"


void test(void (*f)(int [], int), char *data_filename, char *algorithm_name) {
    int *array;
    int array_size;

    array_size = get_num_lines(data_filename);
    array = (int *)malloc(sizeof(int)*array_size);

    read_data_from_file(data_filename, array, array_size);

    printf("%s\n", algorithm_name);
    printf("Input:\t");
    printarray(array, array_size);
    (*f)(array, array_size);
    printf("Output:\t");
    printarray(array, array_size);
    printf("\n");

    free(array);
}


int main(int argc, char *argv[]) {
    char *filename;

    if(argc < 2) {
        printf("Usage: ./bin <data file>\n");
        return 0;
    }

    filename = argv[1];

    test(bubblesort, filename, "bubblesort");
    test(cocktailsort, filename, "cocktailsort");
    test(heapsort, filename, "heapsort");
    test(insertionsort, filename, "insertionsort");
    test(mergesort, filename, "mergesort");
    test(selectionsort, filename, "selectionsort");
    test(shellsort, filename, "shellsort");
    test(quicksort, filename, "quicksort");

    return 0;
}
