#ifndef POISFACTORIAL_H
#define POISFACTORIAL_H

namespace algorithms::poisson::factorial {
    float pmf(float lambda, unsigned int k);
    float cdf(float lambda, unsigned int k);
}

#endif