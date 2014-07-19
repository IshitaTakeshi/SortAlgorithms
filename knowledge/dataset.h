typedef struct Data {
    int label;
    int *vector;
} Data;


//TODO add n_dim as a member
typedef struct Dataset {
    int size;
    Data **array;
} Dataset;


typedef struct DatasetPair {
    Dataset *left;
    Dataset *right;
} DatasetPair;
