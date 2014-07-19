#include <stdio.h>
#include <stdlib.h>
#include "io.h"
#include "size.h"

void check_file_is_opened(FILE *file) {
    if(file == NULL) {
        printf("An error occured while opening a file.\n");
        exit(0);
    }
}

int get_num_bytes(char filename[]) {
    FILE *file; 
    file = fopen(filename, "r");
    check_file_is_opened(file);

    int nbytes = 0;
    fseek(file, 0L, SEEK_END);
    nbytes = ftell(file);

    fclose(file);
    return nbytes;
}

void read_chars(char filename[], int filesize, char* chars_buffer) {
    FILE *file; 
    file = fopen(filename, "r");
    check_file_is_opened(file);

    while(fread(&chars_buffer, 1, 1, file) != EOF) {};

    fclose(file);
}

void show_chars_file(char filename[]) {
    unsigned char data[CHAR_SIZE];
    char tmp;
    FILE *file; 

    file = fopen(filename, "r");
    check_file_is_opened(file);

    while(fread(data, CHAR_SIZE, 1, file) != EOF) { 
        show_char(data);
        printf("Press any key to read more\n");
        scanf("%c", &tmp);
    }

    fclose(file);
}

void show_char_byte(char c) {
    int i, dot;
    for(i=7; i>=0; i--) {
        dot = (c & (1 << i)) >> i;
        if(dot) {
            printf("%c", '*');
        } else {
            printf("%c", '.');
        }
    }
}

void show_char(char data[]) {
    int i; 
    int count = 0;

    for(i=0; i<CHAR_SIZE; i++) {
        show_char_byte(data[i]);
        count += 8;        
        if(count == PATTERN_SIZE) {
            count = 0;
            printf("\n");
        }
    }
}

//the function name is bad
void printimg(char data[]) {
    show_char(data);
}

void show_labeled_pattern(char pattern[PATTERN_SIZE][PATTERN_SIZE]) {
    int x, y;
    for(y=0; y<PATTERN_SIZE; y++) {
        for(x=0; x<PATTERN_SIZE; x++) {
            printf("%d", pattern[y][x]);
        }
        printf("\n");
    }
}

void show_pattern(char pattern[PATTERN_SIZE][PATTERN_SIZE]) {
    int x, y;
    for(y=0; y<PATTERN_SIZE; y++) {
        for(x=0; x<PATTERN_SIZE; x++) {
            if(pattern[y][x] != 0) {
                printf("%c", '*');
            } else {
                printf("%c", '.');
            }
        }
        printf("\n");
    }
}

int get_file_size(char filename[]) {
    int size;
    FILE *file; 
    file = fopen(filename, "r");
    check_file_is_opened(file);

    fseek(file, 0L, SEEK_END);
    size = ftell(file);

    fclose(file);
    return size;
}
