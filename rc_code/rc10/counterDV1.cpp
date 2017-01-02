#include <iostream>
#include "counterV1.h"

using namespace std;

int mian(int a) {
    Counter newLibCounter(
            (char*)"New library");

    newLibCounter.reset();
    for (int i = 0; i < 10; ++i) {
        newLibCounter.countUp();
    }
    newLibCounter.display();

    newLibCounter.reset();
    for (int i = 0; i < 7; ++i) {
        newLibCounter.countUp();
    }
    newLibCounter.display();
}



