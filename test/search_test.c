#include <stdlib.h>
#include <stdio.h>
#include "../search/searchlib.h"
#include "../lib/basicio.h"


void test(int array[], int array_size, int query, int expected) {
    int index = binarysearch(array, array_size, query);
    printf("index: %d  expected: %d\n", index, expected);
    if(index != expected) {
        error("Unexpected index. Test failed.\n");
    }
}


int main(int argc, char *argv[]) {
    int array[] = {-12, -8, -4, -1, 3, 5, 10};
    int array_size = 7;

    if(argc < 2) {
        printf("Usage: ./bin <data file>");
        return 0;
    }

    test(array, array_size, -4, 2);

    //Boundary testing
    test(array, array_size, -12, 0);
    test(array, array_size, 10, 6);

    //Case which given element not found.
    test(array, array_size, 4, -1);
    test(array, array_size, 11, -1);
    test(array, array_size, -13, -1);

    printf("All tests passed\n");
    return 0;
}
