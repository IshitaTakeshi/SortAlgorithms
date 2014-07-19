
void swap(int *a, int *b) {
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

void bubblesort(int array[], int N) {
    int i, j, t; 

    for(i=N-1; i>0; i--) {
        for(j=0; j<i; j++) {
            if(array[j] >= array[j+1]) {
                swap(&array[j], &array[j+1]);
            }
        }
    } 
}

void slide_to_right(int array[], int start, int end) {
    int k, tmp;
    tmp = array[end];
    for(k=end; k>start; k--) {
        array[k] = array[k-1];
    }
    array[start] = tmp;
}

void insertionsort(int array[], int N) {
    int i, j, k, tmp;
    
    if(array[0] > array[1]) {
        swap(&array[0], &array[1]);
    }

    for(i=2; i<N; i++) {
        for(j=0; j<i; j++) {
            if(array[j] > array[i]) {
                slide_to_right(array, j, i);
            }
        }
    }
}


int swap_up(int array[], int array_size) { 
    int swapped = 0;
    int i;
    
    for(i=0; i<array_size; i++) {
        if(array[i] > array[i+1]) {
            swap(&array[i], &array[i+1]);
            swapped = 1;
        }
    }
    return swapped;
}

int swap_down(int array[], int array_size) {
    int swapped = 0;
    int i;
    
    for(i=array_size-1; i<=0; i--) {
        if(array[i] > array[i+1]) {
            swap(&array[i], &array[i+1]);
            swapped = 1;
        }
    }
    return swapped;
}

void cocktailsort(int array[], int array_size) {
    int s1, s2;
    while(1) {
        s1 = swap_up(array, array_size);
        s2 = swap_down(array, array_size);
        if(!s1 && !s2) {
            return;
        }
    }
}



void user_input(int array[], int N) {
    int i, e;
    for(i=0; i<N; i++) {
        scanf("%d", &e);
        array[i] = e;
    }
}

void printarray(int array[], int N) {
    int i;
    for(i=0; i<N; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main(void) {
    int i, N;  
    int array[10]; //= {40, 32, 30, 39, 42, 23, 34, 39, 23, 43};

    N = sizeof(array)/sizeof(int);

    //insertionsort(array, N);

    user_input(array, N);
    printarray(array, N);
    insertionsort(array, N);
    printarray(array, N);
    return 0;
}
