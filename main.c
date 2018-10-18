#include "count.h"
#include <stdio.h>


int main(int argc, char **argv) {
    if (argc == 1) {
        printf("String was not found.\n"); 
        return -1;
    }
    printf("Count %d\n", count(argv[1]));
    return 0;
}
