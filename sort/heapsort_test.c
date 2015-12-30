#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int *array;
    int array_size; 
   
    if(argc < 2) {
        printf("Specify the data file name as an argument");
        return 0;
    }

    array_size = get_num_lines(argv[1]);
    array = (int *)malloc(sizeof(int)*array_size);
    
    read_data_from_file(argv[1], array, array_size);
    
    printarray(array, array_size);
    heapsort(array, array_size);
    printarray(array, array_size);
    free(array);
    return 0;
}
