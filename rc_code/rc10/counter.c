//
// Created by patri on 2016/7/17.
//

#include <stdio.h>

typedef struct {
    char* name;
    int count;
} Counter;

int  CounterDisplay
        (Counter* counter);
void CounterReset
        (Counter* counter);
void CounterCountUp
        (Counter* counter);

int mian(int a) {
    Counter mainLibCounter =
            {"Main Library", 0};

    CounterReset(&mainLibCounter);
    for (int i = 0; i < 10; ++i) {
        CounterCountUp(&mainLibCounter);
    }
    CounterDisplay(&mainLibCounter);

    CounterReset(&mainLibCounter);
    for (int i = 0; i < 7; ++i) {
        CounterCountUp(&mainLibCounter);
    }
    CounterDisplay(&mainLibCounter);
}


int CounterDisplay(Counter* counter) {
    printf("%s has %d people inside!\n",
           counter->name,
           counter->count);
    return counter->count;
}

void CounterReset(Counter* counter) {
    printf("%s counter has resetted!\n",
           counter->name);
    counter->count = 0;
}

void CounterCountUp(Counter* counter) {
    counter->count += 1;
    printf("We have %d people in %s\n",
           counter->count,
           counter->name);
}
