#include "size.h"
#include "converter.h"

void expand(char data[CHAR_SIZE], char pattern[PATTERN_SIZE][PATTERN_SIZE]) {
    int i, j, x, y, dot, count;
    char c;
    char buffer[PATTERN_SIZE*PATTERN_SIZE];

    for(i=0; i<PATTERN_SIZE*PATTERN_SIZE; i++) {
        c = data[i/8]; 
        j = 7-i%8;
        dot = (c & (1 << j)) >> j;
        buffer[i] = dot;
    }

    for(y=0; y<PATTERN_SIZE; y++) {
        for(x=0; x<PATTERN_SIZE; x++) {
            pattern[y][x] = buffer[y*PATTERN_SIZE+x]; 
        }
    }
} 

void compress(char data[CHAR_SIZE], char pattern[PATTERN_SIZE][PATTERN_SIZE]) {
    char buffer[PATTERN_SIZE*PATTERN_SIZE];
    int i, j, x, y;

    for(y=0; y<PATTERN_SIZE; y++) {
        for(x=0; x<PATTERN_SIZE; x++) {
            buffer[y*PATTERN_SIZE+x] = pattern[y][x]; 
        }
    }

    for(i=0; i<PATTERN_SIZE*PATTERN_SIZE; i++) {
        j = 7-i%8; 
        data[i/8] |= buffer[i] << j;
    } 
}
