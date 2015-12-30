#include "basic.h"

void check_file_is_opened(FILE *file);
int get_num_bytes(char filename[]);
void read_chars(char filename[], int filesize, char* chars_buffer);
void show_chars_file(char filename[]);
void show_char(char data[]);
void printimg(char data[]);
void show_labeled_pattern(char pattern[PATTERN_SIZE][PATTERN_SIZE]);
void show_pattern(char pattern[PATTERN_SIZE][PATTERN_SIZE]);
