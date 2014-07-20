#ifndef DATASET_H 
#define DATASET_H
 
struct foo {
        int member;
};
 
typedef struct Data {
    int label;
    int *vector;
} Data;


//TODO add n_dim as a member
typedef struct Dataset {
    int size;
    Data **array;
} Dataset;

typedef struct TestDataset {
    int size;
    int **vectors;
} TestDataset;

typedef struct DatasetPair {
    Dataset *left;
    Dataset *right;
} DatasetPair;

Data* init_data(int label, int *vector);
Dataset* init_dataset();
Dataset *append_dataset(Dataset *dataset, Data *data);
TestDataset *init_test_dataset();

#endif /* DATASET_H */
