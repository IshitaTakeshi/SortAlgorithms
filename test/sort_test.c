#include <stdio.h>
#include <stdlib.h>
#include "../sort/sortlib.h"
#include "../lib/basicio.h"
#include "../lib/array.h"


void test(void (*f)(int [], int), char *algorithm_name) {
    int array[] = {
        -1, -20, -15, -15, 7, 13, 14, -5, -27, 17, 21, 12, 10, -29, 14, -18,
        -7, 15, 7, -32, 26, -14, -12, 28, 19, -14, -5, 17, -29, -18, 7, 18,
        24, -32, -22, -18, 28, 5, 12, 18, -10, 22, -17, -11, 22, 18, -7, 12,
        -28, 18, 27, 2, -3, -23, -7, -31, -12, 13, 5, 2, -10, 5, 26, -16, -4,
        27, 2, -31, -14, 16, 25, 26, 4, 20, -22, 30, -10, 21, 24, -23, -3, 28,
        4, 0, -11, -6, 8, 17, 3, -31, 0, -31, -4, 8, 31, 11, 7, -17, -3, -4
    };
    int expected[] = {
        -32, -32, -31, -31, -31, -31, -29, -29, -28, -27, -23, -23, -22, -22,
        -20, -18, -18, -18, -17, -17, -16, -15, -15, -14, -14, -14, -12, -12,
        -11, -11, -10, -10, -10, -7, -7, -7, -6, -5, -5, -4, -4, -4, -3, -3,
        -3, -1, 0, 0, 2, 2, 2, 3, 4, 4, 5, 5, 5, 7, 7, 7, 7, 8, 8, 10, 11, 12,
        12, 12, 13, 13, 14, 14, 15, 16, 17, 17, 17, 18, 18, 18, 18, 19, 20, 21,
        21, 22, 22, 24, 24, 25, 26, 26, 26, 27, 27, 28, 28, 28, 30, 31
    };

    int array_size = sizeof(array)/sizeof(int);
    printf("array_size: %d\n", array_size);

    printf("%s\n", algorithm_name);
    printf("Input:\t");
    printarray(array, array_size);

    (*f)(array, array_size);

    printf("Output:\t");
    printarray(array, array_size);
    printf("\n");


    if(!equal(array, expected, array_size)) {
        error("The array not sorted correctly. Test failed.\n");
    }
}


int main(int argc, char *argv[]) {
    test(bubblesort, "bubblesort");
    test(heapsort, "heapsort");
    test(insertionsort, "insertionsort");
    test(mergesort, "mergesort");
    test(selectionsort, "selectionsort");
    test(shellsort, "shellsort");
    test(quicksort, "quicksort");

    return 0;
}
