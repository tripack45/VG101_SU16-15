//
// Created by patri on 2016/7/18.
//

#ifndef RC10_COUNTERV1_H
#define RC10_COUNTERV1_H

class Counter {
protected:
    char* name;
    int count;

public:
    Counter(char* name);
    int display();
    void reset();
    void countUp();
    //virtual void countUp();
};

#endif //RC10_COUNTERV1_H
