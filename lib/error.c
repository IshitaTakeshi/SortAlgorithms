#include <stdio.h>
#include <stdlib.h>


void error(char message[]) {
    fprintf(stderr, "%s", message);
    exit(-1);
}
