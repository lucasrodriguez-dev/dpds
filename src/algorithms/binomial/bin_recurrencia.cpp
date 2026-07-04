#include "bin_recurrencia.h"
#include <cmath>

float algorithms::binomial::recurrencia::pmf(unsigned int n, float p, unsigned int k) {
    if(k < 0){
        return 0;
    }
    if(k == 0){
        return std::pow(1-p, n);
    }
    return algorithms::binomial::recurrencia::pmf(n, p, k-1)*(n-k+1)*p/(k*(1-p));
}

float algorithms::binomial::recurrencia::cdf(unsigned int n, float p, unsigned int k) {
    int res = 0;
    for(int i = 0; i <= k; i++){
        res += algorithms::binomial::recurrencia::pmf(n, p, i);
    }
    return res;
}