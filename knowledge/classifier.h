typedef struct Node {
    struct Node *left;
    struct Node *right;
    int label;
    int isleaf;
    int key;
    int criterion;
} Node;


//Node fit(int *X[], int ndim_X, int size_X, int y[], int size_y);
//int* predict(Node tree, int *X[], int data_size);
//void set_n_dimension(int n_dim);
