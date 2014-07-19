#include <stdio.h>
#include <stdlib.h>

#include "io.h"
#include "size.h"
#include "preprocessing.h"
//#include "classifier.h"
//#include "datasetio.h"
//#include "dataset.h"
#include "converter.h"

void test(char data[CHAR_SIZE]) {
    char pattern[PATTERN_SIZE][PATTERN_SIZE];

    expand(data, pattern);
    clear_data(data);
    //label(pattern);
    //noise(pattern, NOISE_THRESHOLD);
    //show_labeled_pattern(pattern);
    noise(pattern, NOISE_THRESHOLD);
	show_labeled_pattern(pattern);
    //show_pattern(pattern);
    //normalize(pattern);
	//show_labeled_pattern(pattern);
    //show_pattern(pattern);
    //outline(pattern);
    //smooth(pattern); 
    //label(pattern);
    //show_labeled_pattern(pattern);
    //clear_pattern(pattern);
    //show_pattern(pattern);
}

void test_multiple(int argc, char *argv[]) { 
    char user_input;
    unsigned char data[CHAR_SIZE];
    FILE *file; 

    if(argc < 2) {
        printf("Specify the file name as an argument.\n");
        exit(0);
    }

    file = fopen(argv[1], "rb");
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

char *filepaths[] = {
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

int labels[] = {
    1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 
    17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 
    33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46,
};

int n_labels = 46;

int main(int argc, char *argv[]) {
    test_multiple(argc, argv);
    return 0;
}
