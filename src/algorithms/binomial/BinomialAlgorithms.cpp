#include "BinomialAlgorithms.h"
#include <cmath>

float algorithms::binomial::pmfRecurrencia(unsigned int n, float p, int k) {
    if(k < 0){
        return 0;
    }
    if(k == 0){
        return std::pow(1-p, n);
    }
    return algorithms::binomial::pmfRecurrencia(n, p, k-1)*(n-k+1)*p/(k*(1-p));
}

float algorithms::binomial::cdfSumatoriaRecurrencia(unsigned int n, float p, int k) {
    int res = 0;
    for(int i = 0; i <= k; i++){
        res += algorithms::binomial::pmfRecurrencia(n, p, i);
    }
    return res;
}