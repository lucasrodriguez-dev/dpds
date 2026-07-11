#include "algorithms/binomialNegativa/binneg_combinaciones.h"
#include "algorithms/combinatoria/combinacion_factoriales.h"
#include <cmath>

using algorithms::combinatoria::factoriales::combinacion;
using std::pow;

namespace algorithms::binomialnegativa::combinaciones {
    float pmf(unsigned int r, float p, unsigned int k){
        return combinacion(k-1,r-1)*pow(p,r)*pow(1-p,k-r);
    }

    float cdf(unsigned int r, float p, unsigned int k){
        int res = 0;
        for(int i = 0; i <= k; i++){
            res += pmf(r, p, i);
        }
        return res;
    }
}