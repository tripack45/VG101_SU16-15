#include <iostream>
#include "counterV2.h"

using namespace std;

int mian(int a) {

    CounterV2 newLibCounter(
            (char*)"New library");

    newLibCounter.reset();
    for (int i = 0; i < 6; ++i) {
        newLibCounter.countUp();
    }
    newLibCounter.display();
    for (int j = 0; j < 3; ++j) {
        newLibCounter.countDown();
    }
    newLibCounter.display();

    newLibCounter.reset();
    for (int i = 0; i < 2; ++i) {
        newLibCounter.countUp();
    }
    newLibCounter.display();
}