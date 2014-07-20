#include <stdio.h>
#include <stdlib.h>
#include "size.h"
#include "io.h"
#include "datasetio.h"
#include "converter.h"
#include "preprocessing.h"

int* convert_pattern_to_vector(char pattern[PATTERN_SIZE][PATTERN_SIZE]) {
    int *vector;
    int i, x, y;
    
    vector = (int *)malloc(sizeof(int)*PATTERN_SIZE*PATTERN_SIZE);
    for(y=0; y<PATTERN_SIZE; y++) {
        for(x=0; x<PATTERN_SIZE; x++) {
            i = y*PATTERN_SIZE + x;
            vector[i] = (int)pattern[y][x];
        }
    } 

    return vector;
}

int *extract_feature_vector(char character[CHAR_SIZE]) {
    int *vector;
    int i;
    char pattern[PATTERN_SIZE][PATTERN_SIZE];

    expand(character, pattern);
    noise(pattern, 10);
    normalize(pattern);

    vector = convert_pattern_to_vector(pattern);
    return vector;
}

Dataset *append_data_array(Dataset *dataset, char filepath[], int label) {
    int size = get_file_size(filepath);
    int n_chars = size/CHAR_SIZE;
    int i;
    char character[CHAR_SIZE];
    FILE *file;
    Data *data; 
    int *vector;
   
    file = fopen(filepath, "rb"); 

    for(i=0; i<n_chars; i++) {
        fread(character, CHAR_SIZE, 1, file);
        //vector = convert_character_to_vector(character);
        vector = extract_feature_vector(character);
        data = init_data(label, vector); 
        dataset = append_dataset(dataset, data);
    }

    fclose(file);
    return dataset;
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

int *load_vector(char filepath[]) {
    FILE *file;
    int *vector;
    char character[CHAR_SIZE];

    file = fopen(filepath, "rb"); 
    
    fread(character, CHAR_SIZE, 1, file);
    vector = extract_feature_vector(character);

    fclose(file);
    return vector;
}

TestDataset *append_vector(TestDataset *test_dataset, int *vector) {
    test_dataset->vectors = (int **)realloc(test_dataset->vectors, 
                                            (test_dataset->size+1)*sizeof(int *));
    test_dataset->vectors[test_dataset->size] = vector;
    test_dataset->size += 1;
    return test_dataset;
}

TestDataset *append_test_dataset(TestDataset *test_dataset, char filepath[]) {
    int size = get_file_size(filepath);
    int n_chars = size/CHAR_SIZE;
    int i;
    FILE *file;
    char character[CHAR_SIZE];
    int *vector;
   
    file = fopen(filepath, "rb"); 

    for(i=0; i<n_chars; i++) {
        fread(character, CHAR_SIZE, 1, file);
        vector = extract_feature_vector(character);
        test_dataset = append_vector(test_dataset, vector);
    }

    fclose(file);
    return test_dataset;
}

TestDataset **load_test_dataset(char *filepaths[], int n_test_files) {
    int i;
    int *vector; 
    int **vectors;
    int n_vectors;

    TestDataset *test_dataset; 
    test_dataset = init_test_dataset();
    printf("size:%d\n", test_dataset->size); 
 
    printf("n_test_files:%d\n", n_test_files);
    for(i=0; i<n_test_files; i++) {
        test_dataset = append_test_dataset(test_dataset, filepaths[i]);
    }
    return test_dataset;
}

//TODO search how to free structures
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
