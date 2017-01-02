#include <iostream>

#include "counterPro.h"
#include "counterV1.h"
#include "counterV2.h"

using namespace std;

class CanRun {
public:
    virtual void run() = 0;
};

class CanRead {
public:
    virtual void read() = 0;
};


class CanWrite {
public:
    virtual void write() = 0;
};


class CanSpeak {
public:
    virtual void speak() = 0;
};

class Human : public CanRead,
              public CanRun,
              public CanWrite,
              public CanSpeak {

};

class Printer: public CanWrite {

};

int mian(int a) {
    Counter    a("Normal Counter");
    CounterPro b("Counter Pro", true);
    CounterV2  c("CounterV2");
    CounterCountTwice(&b);
    b.countUp();
    return 0;
}