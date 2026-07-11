#include "algorithms/binomial/bin_recurrencia.h"
#include <cmath>

using std::pow;

namespace algorithms::binomial::recurrencia {
    float pmf(unsigned int n, float p, unsigned int k) {
        if(k < 0){
            return 0;
        }
        if(k == 0){
            return pow(1-p, n);
        }
        return pmf(n, p, k-1)*(n-k+1)*p/(k*(1-p));
    }

    float cdf(unsigned int n, float p, unsigned int k) {
        int res = 0;
        for(int i = 0; i <= k; i++){
            res += pmf(n, p, i);
        }
        return res;
    }
}