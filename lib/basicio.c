#include <stdio.h>
#include "basicio.h"


int get_num_lines(char filename[]) {
    FILE *file;
    int nlines;
    char c;

    file = fopen(filename, "r");

    nlines = 0;
    while((c=fgetc(file)) != EOF) {
        if(c == '\n') {
            nlines += 1;
        }
    }

    fclose(file);
    return nlines;
}


void read_data_from_file(char filename[], int array[], int array_size) {
    FILE *file;
    int nlines;
    int i;

    file = fopen(filename, "r");

    for(i=0; i<array_size; i++) {
        fscanf(file, "%d", &array[i]);
    }

    fclose(file);
}


void write_data_to_file(char filename[], int array[], int array_size) {
    FILE *file;
    int nlines;
    int i;

    file = fopen(filename, "w");

    for(i=0; i<array_size; i++) {
        fprintf(file, "%d\n", array[i]);
    }

    fclose(file);
}


void read_digits(int array[], int N) {
    int i, e;
    printf("Input %d numbers\n", N);
    for(i=0; i<N; i++) {
        scanf("%d", &e);
        array[i] = e;
    }
}


void printarray(int array[], int N) {
    int i;
    for(i=0; i<N; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}
