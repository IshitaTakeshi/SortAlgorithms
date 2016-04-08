#include "../lib/array.h"


void test(int array1[], int array2[], int array_size, int expected) {
    if(equal(array1, array2, array_size) != expected) {
        error("Test failed.\n");
    }
}


int main() {
    int array1[] = {-3, 4, 3, 2, 8};
    int array2[] = {-3, 4, 3, 3, 8};
    int array_size = 5;
    test(array1, array1, array_size, 1);
    test(array1, array2, array_size, 0);
}
