#include "algorithms/binomial/bin_combinaciones.h"
#include "algorithms/combinatoria/combinacion_factoriales.h"
#include <cmath>

using algorithms::combinatoria::factoriales::combinacion;
using std::pow;

namespace algorithms::binomial::combinaciones {
    float pmf(unsigned int n, float p, unsigned int k) {
        if(k < 0){
            return 0;
        }
        if(k == 0){
            return pow(1-p, n);
        }
        return combinacion(n,k)*pow(p,k)*pow(1-p,n-k);
    }

    float cdf(unsigned int n, float p, unsigned int k) {
        int res = 0;
        for(int i = 0; i <= k; i++){
            res += pmf(n, p, i);
        }
        return res;
    }
}