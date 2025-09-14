#include <stdio.h>
#include <stdint.h>

int main() {

    struct {
        unsigned int width_validated;
        unsigned int height_validated;
    } status1;

    struct {
        unsigned int width_validated : 1;
        unsigned int height_validated : 1;
    } status2;

    printf("size of unsigned int: %ld\n", sizeof(unsigned int));
    printf("size of status 1: %ld\n", sizeof(status1));
    printf("size of status 2: %ld\n", sizeof(status2));

    return 0;
}