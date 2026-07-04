#include "hip_combinaciones.h"
#include "combinacion_factorial.h"
#include <cmath>

float algorithms::hipergeometrica::combinaciones::pmf(unsigned int n, unsigned int N, unsigned int K, float k){
    return algorithms::combinatoria::factorial::combinacion(K,k)*algorithms::combinatoria::factorial::combinacion(N-K,n-k)/algorithms::combinatoria::factorial::combinacion(N,n);
}

float algorithms::hipergeometrica::combinaciones::cdf(unsigned int n, unsigned int N, unsigned int K, float k){
    int res = 0;
    for(int i = 0; i <= k; i++){
        res += algorithms::hipergeometrica::combinaciones::pmf(n, N, K, i);
    }
    return res;
}