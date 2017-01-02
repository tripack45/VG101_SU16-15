#include <stdlib.h>
#include <time.h>

int *getRandomVector(int n) {
    int* a = (int*)calloc(100, sizeof(int));
    srand(time(NULL));
    for (int i = 0; i < n; ++i) {
        a[i] = rand();
    }
    return a;
}

int main() {
    int* num = getRandomVector(10);
    free(num);
    return 0;
}

