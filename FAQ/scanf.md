#Why `scanf("%s", <char>)` is  a bad idea?

Many of you use code like:

```c
char c = 0;
scanf("%s", &c);
```

to input a single character. It seems pretty useful, since `scanf("%s")` automatically ignore all blank characters (spaces, newline characters, etc.). But there is a hazard of doing this. 

Before we explain the hazard, the only correct way to input string safely is through:

```c
char s[100] = 0;
scanf("%s", s);
```

Where `s[]` must either itself be a large enough array to hold all user input characters, or points to a large enough memory region. 

We provide an example code to show why the trivial solution is harmful:

```c
#include <stdio.h>

void foo();

int main() {
    int a[3] = {0}; 
    printf("Old value of a[0]: %d \n", a[0]); 
    // should be zero
    foo();
    printf("New value of a[0]: %d \n ",a[0]);
     // a[0] become random number
    return 0;
}

void foo() {
    char c=0;
    puts("Input string:"); 
    // type 'a', then press enter
    scanf("%s", &c);
}
```
**Note this example is platform dependent, should work on Windows**

In the above code, `a` is a **local** array in function `main()`. In theory,  `foo()` has no effect on what's happening in `main()`, so both `printf()` in `main()` should both print `0`. However, after inputting a single character `"a"` in `foo()`, the value of `a[0]` in `main()` changed to a "random" value.
If by accident more then 1 characters are provided, the program crashes.

This shows using `scanf("%s")` in this way is not safe! 

Note (if you are interested).
 * The reason behind that strange result is that `scanf()` reads character one by one to the specified memory regeon. If too many characters are input, some other memory region gets redacted unexpectedly, causing crashes. 