#include <stdio.h>
#include <stdlib.h>
#include "size.h"
#include "io.h"
#include "datasetio.h"
#include "converter.h"

int* convert_character_to_vector(char *character) {
    int *vector;
    
    int i, x, y;
    char pattern[PATTERN_SIZE][PATTERN_SIZE];
    expand(character, pattern); 
    
    vector = (int *)malloc(sizeof(int)*PATTERN_SIZE*PATTERN_SIZE);
    for(y=0; y<PATTERN_SIZE; y++) {
        for(x=0; x<PATTERN_SIZE; x++) {
            i = y*PATTERN_SIZE + x;
            vector[i] = (int)pattern[y][x];
        }
    } 

    return vector;
}

Dataset *append(Dataset *dataset, char *character, int label) {
    Data *data; 
    int *vector;

    vector = convert_character_to_vector(character);
    
    data = (Data *)malloc(sizeof(Data));
    data->label = label;
    data->vector = vector;
    
    dataset->array = realloc(dataset->array, (dataset->size+1)*sizeof(&data));
    
    printf("data is at %p\n", data);
    dataset->array[dataset->size] = data; 
    dataset->size += 1;
    return dataset;
}

Dataset *append_data_array(Dataset *dataset, char filename[], int label) {
    int size = get_file_size(filename);
    int n_chars = size/CHAR_SIZE;
    int i;
    char character[CHAR_SIZE];
    FILE *file;
   
    file = fopen(filename, "rb");
    
    for(i=0; i<n_chars; i++) {
        fread(character, CHAR_SIZE, 1, file);
        dataset = append(dataset, character, label);
    }

    fclose(file);
    return dataset;
}

Dataset *init_dataset() {
    Dataset dataset;
    dataset.size = 0;
    return &dataset; 
}

Dataset *load_dataset(char *filepaths[], int labels[], int n_labels) {
    Dataset *dataset;
    int i;
    
    dataset = init_dataset();
    for(i=0; i<n_labels; i++) {
        dataset = append_data_array(dataset, filepaths[i], labels[i]);
    }

    return dataset;
}

//TODO
void free_dataset(Dataset *dataset) {
    int i;
    for(i=0; i<dataset->size; i++) {
        free(dataset->array[i]->vector);
    }
}

void print_dataset(Dataset *dataset, int n_dim) {
    int i, j;
     
    for(i=0; i<dataset->size; i++) {
        printf("label:%2d vector:%p\n", dataset->array[i]->label, 
                                        dataset->array[i]->vector);
    }
}
