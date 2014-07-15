#include "dataset.h"

Dataset *load_dataset(char *filepaths[], int labels[], int n_labels);
void free_dataset(Dataset *dataset);
void print_dataset(Dataset *dataset, int n_dim);
