//
// Created by patri on 2016/7/18.
//

#ifndef RC10_COUNTERV2_H
#define RC10_COUNTERV2_H

#include "counterV1.h"

class CounterV2 : public Counter {
public:
    CounterV2(char* str);
    int countDown();
};

#endif //RC10_COUNTERV2_H
