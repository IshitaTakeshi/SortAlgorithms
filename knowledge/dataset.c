#include <stdlib.h>
#include "dataset.h"
#include <stdlib.h>

Data* init_data(int label, int *vector) {
    Data *data;        
    data = (Data *)malloc(sizeof(Data));
    data->label = label;
    data->vector = vector;
    return data;
}

Dataset* init_dataset() {
    Dataset *dataset;
    dataset = (Dataset *)malloc(sizeof(Dataset));
    dataset->size = 0;
    dataset->array = (Data **)malloc(dataset->size*sizeof(Data *));
    return dataset;
}

//TODO chast realloc
Dataset *append_dataset(Dataset *dataset, Data *data) {
    dataset->array = (Data **)realloc(dataset->array, 
                                      (dataset->size+1)*sizeof(Data *));
    dataset->array[dataset->size] = data;
    dataset->size += 1;
    return dataset;
}

TestDataset *init_test_dataset() {
    TestDataset *test_dataset;
    test_dataset = (TestDataset *)malloc(sizeof(TestDataset));
    test_dataset->size = 0;
    test_dataset->vectors = (int **)malloc(test_dataset->size*sizeof(int *));
    return test_dataset;
}
