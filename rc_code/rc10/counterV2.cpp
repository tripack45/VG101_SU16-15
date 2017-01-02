//
// Created by patri on 2016/7/18.
//
#include <iostream>
using namespace std;

#include "counterV2.h"

CounterV2::CounterV2(char *str) :
        Counter(str) {}

int CounterV2::countDown() {
    count -= 1;
    cout << "Leave 1 person, remains "
        << count << " people!" << endl;
}

