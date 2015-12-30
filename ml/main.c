#include <stdio.h>
#include <stdlib.h>

#include "io.h"
#include "basic.h"
#include "preprocessing.h"

void test(char data[CHAR_SIZE]) {
    char pattern[PATTERN_SIZE][PATTERN_SIZE];

    expand(data, pattern);
    clear_data(data);
    //label(pattern);
    //noise(pattern, NOISE_THRESHOLD);
    //show_labeled_pattern(pattern);
    noise(pattern, NOISE_THRESHOLD);
    show_pattern(pattern);
    normalize(pattern);
    show_pattern(pattern);
    outline(pattern);
    //smooth(pattern); 
    //label(pattern);
    //show_labeled_pattern(pattern);
    //clear_pattern(pattern);
    //show_pattern(pattern);
}

void test_multiple(char *filename) {
    char user_input;
    unsigned char data[CHAR_SIZE];
    FILE *file; 

    file = fopen(filename, "r");
    check_file_is_opened(file);

    while(fread(data, CHAR_SIZE, 1, file) != EOF) { 
        test(data);
        printf("Type '0' to exit\n");
        printf("Or press another key to read more\n");
        scanf("%c", &user_input);
        if(user_input == '0') {
            exit(0);
        }
    }

    fclose(file);
}

int main(int argc, char *argv[]) {

    if(argc < 2) {
        printf("Specify the file name as an argument.\n");
        exit(0);
    }

    test_multiple(argv[1]); 
    return 0;
}
