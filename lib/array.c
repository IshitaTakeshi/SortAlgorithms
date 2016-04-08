//return 1 if arrays are same, 0 if not.
int equal(int array1[], int array2[], int array_size) {
    int i;
    for(i = 0; i < array_size; i++) {
        if(array1[i] != array2[i]) {
            return 0;
        }
    }
    return 1;
}
