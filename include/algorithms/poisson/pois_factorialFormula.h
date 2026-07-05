#ifndef POISFACTORIALFORMULA_H
#define POISFACTORIALFORMULA_H

namespace algorithms::poisson::factorialFormula {
    float pmf(float lambda, unsigned int k);
    float cdf(float lambda, unsigned int k);
}

#endif