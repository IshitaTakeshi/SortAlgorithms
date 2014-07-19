#include "size.h"

void expand(char data[CHAR_SIZE], char pattern[PATTERN_SIZE][PATTERN_SIZE]);
void compress(char data[CHAR_SIZE], char pattern[PATTERN_SIZE][PATTERN_SIZE]);
void outline(char pattern[PATTERN_SIZE][PATTERN_SIZE]);
void smooth(char pattern[PATTERN_SIZE][PATTERN_SIZE]);
void normalize(char pattern[PATTERN_SIZE][PATTERN_SIZE]);
int label(char pattern[PATTERN_SIZE][PATTERN_SIZE]);
void noise(char pattern[PATTERN_SIZE][PATTERN_SIZE], int size);
void clear_pattern(char pattern[PATTERN_SIZE][PATTERN_SIZE]);
void clear_data(char data[CHAR_SIZE]);
