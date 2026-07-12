#include "algorithms/hipergeometrica/hip_combinaciones.h"
#include "algorithms/combinatoria/combinacion_factoriales.h"
#include <cmath>

using algorithms::combinatoria::factoriales::combinacion;

namespace algorithms::hipergeometrica::combinaciones {
    float pmf(unsigned int n, unsigned int N, unsigned int K, float k){
        return combinacion(K,k)*combinacion(N-K,n-k)/combinacion(N,n);
    }

    float cdf(unsigned int n, unsigned int N, unsigned int K, float k){
        int res = 0;
        for(size_t i = 0; i <= k; i++){
            res += pmf(n, N, K, i);
        }
        return res;
    }
}