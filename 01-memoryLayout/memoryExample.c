#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int globalvar;

int main(int argc, char **argv)
{
    static int bssvar;
    int stackvar1 = 41;
    int stackvar2;
    char * datavar = "Foobar";


    char * heapbuffer = malloc(16);

    strncpy(heapbuffer, "Hello", 6);

    printf("globalvar is at %p and contains: %d\n", &globalvar, globalvar);

    printf("bssvar is at %p and contains: %d\n", &bssvar, bssvar);

    printf("stackvar1 is at %p and contains: %d\n", &stackvar1, stackvar1);
    printf("stackvar2 is at %p and contains: %d\n", &stackvar2, stackvar2);
    printf("datavar is at %p and contains: %s\n", datavar, datavar);

    printf("heapbuffer is at %p and contains %s\n", heapbuffer, heapbuffer);

    return 0;
}

