//
// Created by patri on 2016/7/19.
//

#include "counterPro.h"

#include <iostream>
using namespace std;

CounterPro::CounterPro(char *str,
                       bool power) :
        Counter(str) {
    isPowerOn = power;
}

void CounterPro::countUp() {
    cout << "Counter Pro Counting" << endl;
    if (isPowerOn) {
        count += 1;
        cout << "We have " << count
        << " people!" << endl;
    } else {
        cout << "No power!" << endl;
    }
}

