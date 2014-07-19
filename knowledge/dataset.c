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

Dataset *append_dataset(Dataset *dataset, Data *data) {
    dataset->array = realloc(dataset->array, (dataset->size+1)*sizeof(data));
    dataset->array[dataset->size] = data;
    dataset->size += 1;
    return dataset;
}
