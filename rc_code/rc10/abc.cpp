#include <iostream>
#include <fstream>

using namespace std;


class A {
public:
    int getA() const;

    void setA(int a);

    int getB() const;

    void setB(int b);

    int getC() const;

    void setC(int c);

    int getD() const;

    void setD(int d);

private:
    int a;
int b;
int c;
int d;
};

class Multiplier {
private:
    int scale;
public:
    Multiplier(int k) {scale = k;}
    int operator() (int n) {return n * scale;}
};

int main() {
    Multiplier m2(2);
    Multiplier m3(3);

    cout << m2(10) << " " << m3(10) << endl;
}


int A::getA() const {
    return a;
}

void A::setA(int a) {
    A::a = a;
}

int A::getB() const {
    return b;
}

void A::setB(int b) {
    A::b = b;
}

int A::getC() const {
    return c;
}

void A::setC(int c) {
    A::c = c;
}

int A::getD() const {
    return d;
}

void A::setD(int d) {
    A::d = d;
}


