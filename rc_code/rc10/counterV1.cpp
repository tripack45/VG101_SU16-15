//
// Created by patri on 2016/7/18.
//
#include <iostream>

#include "counterV1.h"

using namespace std;

Counter::Counter(char *str) {
    name = str;
    count = 0;
}

int Counter::display() {
    cout << name << " has "
    << count << " people inside!"
    << endl;
    return count;
}

void Counter::reset() {
    count = 0;
   std::cout << name
    << " counter reset!" << endl;
}

void Counter::countUp() {
    cout << "Counter Type Counting!" << endl;
    count += 1;
    cout << "We have " << count
    << " people!" << endl;
}
