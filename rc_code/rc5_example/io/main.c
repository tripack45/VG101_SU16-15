#include <stdio.h>

#define CLEAR_INPUT() fflush(stdin);

char s[40];

#define INPUT

#ifdef OUTPUT
int main() {
    int var = 97;
    int nl = 10;
    printf("\n=====\n");
    printf("%d | %d ", var, nl);
    printf("\n=====\n");
    printf("%c | %c", var, nl);
    printf("\n=====\n");
    printf("Look what happended?");
}
#endif

#ifdef INPUT
int main() {
    int a = 0, b = 0, c = 0;
    printf("1st:");CLEAR_INPUT();
    scanf("%d", &a);
    printf("%d\n", a-100);

    printf("2nd:");CLEAR_INPUT();
    scanf("%c%c%c", &a, &b, &c);
    printf("%d %d %d\n", a, b, c);

    printf("3rd:");CLEAR_INPUT();
    scanf("%s", s);
    printf("%s\n", s);
}
#endif