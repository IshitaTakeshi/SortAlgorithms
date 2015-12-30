#include <stdio.h>
#include <stdlib.h>
#include "basic.h"

void expand(char data[CHAR_SIZE], 
        char pattern[PATTERN_SIZE][PATTERN_SIZE]) {
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

void compress(char data[CHAR_SIZE], 
        char pattern[PATTERN_SIZE][PATTERN_SIZE]) {
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

int abs(int n) {
    if(n > 0) {
        return n;
    }
    return -n;
}

int differentiate(char pattern[PATTERN_SIZE][PATTERN_SIZE], char x, char y) {
    int dx, dy;
    dx = (int)(pattern[y+1][x]-pattern[y][x]);
    dy = (int)(pattern[y][x+1]-pattern[y][x]);
    return abs(dx)+abs(dy);
}

void outline(char pattern[PATTERN_SIZE][PATTERN_SIZE]) {
    int y, x, d;
    for(y=0; y<PATTERN_SIZE-1; y++) {
        for(x=0; x<PATTERN_SIZE-1; x++) {
            d = differentiate(pattern, x, y);
            if(d == 0) {
                pattern[y][x] = 0;
            } else {
                pattern[y][x] = 1;
            }
        }
    }
}


void smooth_square(char pattern[PATTERN_SIZE][PATTERN_SIZE],  int x, int y, 
        int matched_pattern[], int replaced_pattern[], 
        int square_size) {
    int px, py;
    int matched = 1;

    //the region pattern[y:y+square_size, x:x+square_size] is equal to 
    //matched_pattern
    for(py=0; py<square_size; py++) {
        for(px=0; px<square_size; px++) {
            matched &= (pattern[y+py][x+px] == matched_pattern[py*square_size+px]);
        }
    }

    if(matched) {
        for(py=0; py<square_size; py++) {
            for(px=0; px<square_size; px++) {
                pattern[y+py][x+px] = replaced_pattern[py*square_size+px];
            }
        }
    }
}

//C is ugly so I made this
//FIX the name `pattern` is confusing 
void reinit_pattern(int p[], 
        int e0, int e1, int e2, 
        int e3, int e4, int e5, 
        int e6, int e7, int e8) {
    p[0] = e0;
    p[1] = e1;
    p[2] = e2;
    p[3] = e3;
    p[4] = e4;
    p[5] = e5;
    p[6] = e6;
    p[7] = e7;
    p[8] = e8;
}

void turn_pattern_upside_down(char p[]) {
    int i;
    int size = sizeof(p);

    for(i=0; i<size; i++) {
        p[size-i] = p[i]; 
    }
}

void smooth(char pattern[PATTERN_SIZE][PATTERN_SIZE]) {
    int x, y;
    int square_size = 3;
    int matched_pattern[9];
    int replaced_pattern[9];

    for(y=0; y<PATTERN_SIZE-square_size; y++) {
        for(x=0; x<PATTERN_SIZE-square_size; x++) {
            reinit_pattern(matched_pattern, 
                    0, 1, 0, 
                    1, 1, 1, 
                    1, 1, 1
                    );
            reinit_pattern(replaced_pattern, 
                    0, 0, 0, 
                    1, 1, 1, 
                    1, 1, 1
                    );
            smooth_square(pattern, x, y, matched_pattern, replaced_pattern, 
                    square_size);
            reinit_pattern(matched_pattern, 
                    1, 1, 0, 
                    1, 1, 1, 
                    1, 1, 0
                    );
            reinit_pattern(replaced_pattern, 
                    1, 1, 0, 
                    1, 1, 0, 
                    1, 1, 0
                    );
            smooth_square(pattern, x, y, matched_pattern, replaced_pattern, 
                    square_size);

            reinit_pattern(matched_pattern, 
                    1, 1, 1, 
                    1, 1, 1, 
                    0, 1, 0
                    );
            reinit_pattern(replaced_pattern, 
                    1, 1, 1, 
                    1, 1, 1,
                    0, 0, 0
                    );
            smooth_square(pattern, x, y, matched_pattern, replaced_pattern, 
                    square_size);

            reinit_pattern(matched_pattern, 
                    0, 1, 1, 
                    1, 1, 1, 
                    0, 1, 1
                    );
            reinit_pattern(replaced_pattern, 
                    0, 1, 1, 
                    0, 1, 1, 
                    0, 1, 1
                    );
            smooth_square(pattern, x, y, matched_pattern, replaced_pattern, 
                    square_size);

            reinit_pattern(replaced_pattern, 
                    1, 1, 1, 
                    1, 1, 1, 
                    1, 1, 1
                    );

            reinit_pattern(matched_pattern, 
                    1, 0, 1, 
                    1, 1, 1, 
                    1, 1, 1
                    );
            smooth_square(pattern, x, y, matched_pattern, replaced_pattern, 
                    square_size);

            reinit_pattern(matched_pattern, 
                    1, 1, 1, 
                    1, 1, 0, 
                    1, 1, 1
                    );
            smooth_square(pattern, x, y, matched_pattern, replaced_pattern, 
                    square_size);

            reinit_pattern(matched_pattern, 
                    1, 1, 1, 
                    1, 1, 1, 
                    1, 0, 1
                    );
            smooth_square(pattern, x, y, matched_pattern, replaced_pattern, 
                    square_size);

            reinit_pattern(matched_pattern, 
                    1, 1, 1, 
                    0, 1, 1, 
                    1, 1, 1
                    );
            smooth_square(pattern, x, y, matched_pattern, replaced_pattern, 
                    square_size);
        }
    }
}

void normalize(char pattern[PATTERN_SIZE][PATTERN_SIZE]) {
    char normalized_pattern[PATTERN_SIZE][PATTERN_SIZE];
    int x, y;
    int x_end = 0;
    int y_end = 0;
    int x_begin = PATTERN_SIZE;
    int y_begin = PATTERN_SIZE;
    int x_center = PATTERN_SIZE/2;
    int y_center = PATTERN_SIZE/2;
    float x_len, y_len;

    for(y=0; y<PATTERN_SIZE; y++) {
        for(x=0; x<PATTERN_SIZE; x++) {
            if(pattern[y][x] != 0) {
                if(x < x_begin) x_begin = x;
                if(y < y_begin) y_begin = y;
                if(x > x_end) x_end = x;
                if(y > y_end) y_end = y;
            }
        }
    }

    x_len = x_end - x_begin;
    y_len = y_end - y_begin;

    if(x_len < 0 || y_len < 0) {
        printf("Invalid data\n");
        return;
    }

    int px, py;
    for(y=0; y<PATTERN_SIZE; y++) {
        for(x=0; x<PATTERN_SIZE; x++) {
            px = (int)(x_center + (x-x_center)*(x_len/PATTERN_SIZE));
            py = (int)(y_center + (y-y_center)*(y_len/PATTERN_SIZE));
            normalized_pattern[y][x] = pattern[py][px];
        }
    }

    for(y=0; y<PATTERN_SIZE; y++) {
        for(x=0; x<PATTERN_SIZE; x++) {
            pattern[y][x] = normalized_pattern[y][x];
        }
    }
}


void floodfill(char pattern[PATTERN_SIZE][PATTERN_SIZE], 
        int x, int y, int label) {
    if(pattern[y][x] != 1) {
        return;
    }

    pattern[y][x] = label;
    if(x > 0) { 
        floodfill(pattern, x-1, y, label); //left
    }

    if(y > 0) {
        floodfill(pattern, x, y-1, label); // up
    }

    if(x < PATTERN_SIZE-1) {
        floodfill(pattern, x+1, y, label); //right
    }

    if(y < PATTERN_SIZE-1) { 
        floodfill(pattern, x, y+1, label); //down
    }
}

int label_at_once(char pattern[PATTERN_SIZE][PATTERN_SIZE], int label) {
    int x, y;

    for(y=0; y<PATTERN_SIZE; y++) {
        for(x=0; x<PATTERN_SIZE; x++) {
            if(pattern[y][x] == 1) {
                floodfill(pattern, x, y, label);
                return 1;
            }
        }
    }
    return 0;
}


int label(char pattern[PATTERN_SIZE][PATTERN_SIZE]) {
    int label = 2;

    while(label_at_once(pattern, label)) {
        label += 1;
        if(label == 255) {
            return 1;
        }
    } 

    return 0;
}

void denoise(char pattern[PATTERN_SIZE][PATTERN_SIZE], int label) {
    int x, y;
    for(y=0; y<PATTERN_SIZE; y++) {
        for(x=0; x<PATTERN_SIZE; x++) {
            if(pattern[y][x] == label) {
                pattern[y][x] = 0;
            }
        }
    }
}

void noise(char pattern[PATTERN_SIZE][PATTERN_SIZE], int size) {
    int x, y;
    int label;
    int labels_num[256];

    for(label=2; label<256; label++) {
        labels_num[label] = 0;
        for(y=0; y<PATTERN_SIZE; y++) {
            for(x=0; x<PATTERN_SIZE; x++) {
                if(pattern[y][x] == label) {
                    labels_num[label] += 1;
                }
            }
        }
    }

    for(label=2; label<256; label++) {
        if(labels_num[label] < size) {
            denoise(pattern, label);
        }
    } 
}


void clear_pattern(char pattern[PATTERN_SIZE][PATTERN_SIZE]) {
    int x, y;
    for(y=0; y<PATTERN_SIZE; y++) {
        for(x=0; x<PATTERN_SIZE; x++) {
            pattern[y][x] = 0;
        }
    }
}

void clear_data(char data[CHAR_SIZE]) {
    int i;
    for(i=0; i<CHAR_SIZE; i++) {
        data[i] = 0;
    }
}

