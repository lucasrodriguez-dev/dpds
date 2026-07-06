#ifndef HIPCOMBINACIONES_H
#define HIPCOMBINACIONES_H

namespace algorithms::hipergeometrica::combinaciones {
    float pmf(unsigned int n, unsigned int N, unsigned int K, float k);
    float cdf(unsigned int n, unsigned int N, unsigned int K, float k);
}

#endif