#ifndef BINRECURRENCIA_H
#define BINRECURRENCIA_H

namespace algorithms::binomial::recurrencia {
    float pmf(unsigned int n, float p, unsigned int k);
    float cdf(unsigned int n, float p, unsigned int k);
}

#endif