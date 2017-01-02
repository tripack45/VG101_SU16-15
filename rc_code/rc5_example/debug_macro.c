#include "stdio.h"

#define DEBUG
#ifdef DEBUG
    #define _D(x) x
#else
    #define _D(x)
#endif

int main() {
    _D(
            printf("I will not be printed\n");
            printf("I will not either");
    )
    printf("Hello I'm here\n");
}