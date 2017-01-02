#include <stdio.h>
#include <math.h>

typedef struct {
    double re;
    double im;
}Complex;

void complexABS(Complex *c, double* dest, int size) {
    for (int i = 0; i < size; ++i) {
        double reSquared = c[i].re * c[i].re;
        double imSquared = c[i].im * c[i].im;
        dest[i] = sqrt(reSquared + imSquared);
    }
    return;
}


int main() {

}
