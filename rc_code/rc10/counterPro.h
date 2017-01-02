//
// Created by patri on 2016/7/19.
//

#ifndef RC10_COUNTERPRO_H
#define RC10_COUNTERPRO_H

#include "counterV1.h"

class CounterPro : public Counter {
public:
    bool isPowerOn;
public:
    CounterPro(char* str,
               bool power);
    void countUp();
};


#endif //RC10_COUNTERPRO_H

