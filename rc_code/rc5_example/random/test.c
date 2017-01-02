#include <stdio.h>

int a = 1; //Global variable

int main() {
    f1();
    f2();
    a++;
    f1();
    f2();

}

int f1() {
    int a = 1;
    printf("f1 %d\n", a);
}


int f2() {
    int a = 2;
    printf("f2 %d\n", a);
}