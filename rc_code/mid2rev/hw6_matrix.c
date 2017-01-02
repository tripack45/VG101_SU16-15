#include <stdio.h>

int getNumberFromFile(char* file, int* dest, int size);

int main() {
    int a[20] = {0};
    int count = getNumberFromFile("matrix.txt", a, 20);
    for (int i = 0; i < count; ++i) {
        printf("a[%d]=%d\n",i, a[i]);
    }
    printf("Read %d numbers", count);
}

int getNumberFromFile(char* file,
                      int* dest,
                      int size) {
    FILE* fp = fopen(file, "r");
    if (fp == NULL) {
        puts("Error");
        return -1;
    }
    int num = 0; int count = 0;
    while (fscanf(fp, "%d", &num) != EOF) {
        if (count == size){
            fclose(fp);
            return -2;
        }
        dest[count] = num;
        count++;
    }
    fclose(fp);
    return count;
}