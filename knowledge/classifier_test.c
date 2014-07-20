#include <stdio.h>
#include "datasetio.h"
#include "classifier.h"
#include "size.h"
//#include "visualizer.h"


double accuracy_test(Node *tree, Dataset *dataset) {
    int result;
    int label;
    int i;
     
    int n_corrects = 0;
    for(i=0; i<dataset->size; i++) {
        result = predict_once(tree, dataset->array[i]->vector);
        if(result == dataset->array[i]->label) {
            n_corrects += 1;
        }
    }
    
    return (double)n_corrects/(double)dataset->size;
}

void test_large(void) {
    char *training_filepaths[] = {
        "images/01.img", "images/02.img", "images/03.img", "images/04.img", 
        "images/05.img", "images/06.img", "images/07.img", "images/08.img", 
        "images/09.img", "images/10.img", "images/11.img", "images/12.img", 
        "images/13.img", "images/14.img", "images/15.img", "images/16.img", 
        "images/17.img", "images/18.img", "images/19.img", "images/20.img", 
        "images/21.img", "images/22.img", "images/23.img", "images/24.img", 
        "images/25.img", "images/26.img", "images/27.img", "images/28.img", 
        "images/29.img", "images/30.img", "images/31.img", "images/32.img", 
        "images/33.img", "images/34.img", "images/35.img", "images/36.img", 
        "images/37.img", "images/38.img", "images/39.img", "images/40.img", 
        "images/41.img", "images/42.img", "images/43.img", "images/44.img", 
        "images/45.img", "images/46.img", 
    };

    int training_labels[] = {
        1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 
        17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 
        33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46,
    };

    int n_training_labels = 46;

    char *test_filepaths[] = {
        "images/c01.img", "images/c02.img", "images/c03.img", "images/c04.img", 
        "images/c05.img", "images/c06.img", "images/c07.img", "images/c08.img", 
        "images/c09.img", "images/c10.img", "images/c11.img", "images/c12.img", 
        "images/c13.img", "images/c14.img", "images/c15.img", "images/c16.img", 
        "images/c17.img", "images/c18.img", "images/c19.img", "images/c20.img", 
        "images/c21.img", "images/c22.img", "images/c23.img", "images/c24.img", 
        "images/c25.img", "images/c26.img", "images/c27.img", "images/c28.img", 
        "images/c29.img", "images/c30.img", "images/c31.img", "images/c32.img", 
        "images/c33.img", "images/c34.img", "images/c35.img", "images/c36.img", 
        "images/c37.img", "images/c38.img", "images/c39.img", "images/c40.img", 
        "images/c41.img", "images/c42.img", "images/c43.img", "images/c44.img", 
        "images/c45.img", "images/c46.img", 
    };

    int test_labels[] = {
        1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 
        17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 
        33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46,
    };

    int n_test_labels = 46;

    Dataset *dataset;
    Dataset *test_dataset;
    int *results;
    Node *tree;

    dataset = load_dataset(training_filepaths, training_labels, n_training_labels);
    tree = fit(dataset, VECTOR_SIZE, 10);
    
    show_tree(tree);
    
    test_dataset = load_dataset(test_filepaths, test_labels, n_test_labels);

    double accuracy;
    accuracy = accuracy_test(tree, test_dataset);
    printf("accuracy:%lf\n", accuracy);
    
    free_dataset(dataset);
    free_dataset(test_dataset);
}

void test_small(void) {
    char *training_filepaths[] = {
        "images/01.img", "images/02.img", "images/03.img", "images/04.img", 
        "images/05.img", "images/06.img"
    };
    int training_labels[] = {
        1, 2, 3, 4, 5, 6
    };
    int n_training_labels = 6;

    char *test_filepaths[] = {
        "images/c01.img", "images/c02.img", "images/c03.img", "images/c04.img", 
        "images/c05.img", "images/c06.img"
    };
    int test_labels[] = {
        1, 2, 3, 4, 5, 6
    };
    int n_test_labels = 6;

    Dataset *dataset;
    Node *tree;
    Dataset *test_dataset;
    int *results;

    dataset = load_dataset(training_filepaths, training_labels, n_training_labels);
    tree = fit(dataset, VECTOR_SIZE, 10);
    show_tree(tree);
    free_dataset(dataset);
    test_dataset = load_dataset(training_filepaths, training_labels, 
                                n_training_labels);
    //test_dataset = load_dataset(test_filepaths, test_labels, n_test_labels);
    //test_dataset = load_test_dataset(test_filepaths, n_test_labels);
    //results = predict(tree, test_dataset, n_test_labels);
    double accuracy;
    accuracy = accuracy_test(tree, test_dataset);
    printf("accuracy:%lf\n", accuracy);
    //free(results);
}

int main(void) {
    test_small();
    return 0;
}
