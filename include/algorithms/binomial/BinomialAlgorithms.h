#ifndef BINOMIALALGORITHMS_H
#define BINOMIALALGORITHMS_H

namespace algorithms::binomial {
    float pmfRecurrencia(unsigned int n, float p, int k);
    //float pmfFactoriales(unsigned int n, float p, int k);
    float cdfSumatoriaRecurrencia(unsigned int n, float p, int k);
}

#endif