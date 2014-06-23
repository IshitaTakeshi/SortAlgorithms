#include <stdio.h>
#include <stdlib.h>

void printarray(int array[], int N) {
    int i;
    for(i=0; i<N; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int get_line_count(FILE *file) {
    char c;
    int count = 0;
    while((c = fgetc(file)) != EOF) {
        if(c == '\n') {
            count += 1;
        }
    }

    return count;
}

int main(int argc, char *argv[]) {
    int nlines, i;
    int *array;
    FILE *file;
    char *line = NULL;
    size_t length = 0;
    ssize_t read;


    if(argc < 2) {
        printf("Specify the file name.");
    }

    file = fopen(argv[1], "r");
    if (file == NULL)
        return -1;

    nlines = get_line_count(file);
    array = (int *)malloc(sizeof(int) * nlines);

    i = 0;
    while ((read = getline(&line, &length, file)) != -1) {
        fscanf(file, "%d", &i);//&array[i]);
        printf("%d", i);
    }

    printarray(array, sizeof(int) * nlines);

    fclose(file);

    return 0;
}
