#include "bin_combinaciones.h"
#include "combinacion_factorial.h"
#include <cmath>

float algorithms::binomial::combinaciones::pmf(unsigned int n, float p, unsigned int k) {
    if(k < 0){
        return 0;
    }
    if(k == 0){
        return std::pow(1-p, n);
    }
    return algorithms::combinatoria::factorial::combinacion(n,k)*std::pow(p,k)*std::pow(1-p,n-k);
}

float algorithms::binomial::combinaciones::cdf(unsigned int n, float p, unsigned int k) {
    int res = 0;
    for(int i = 0; i <= k; i++){
        res += algorithms::binomial::combinaciones::pmf(n, p, i);
    }
    return res;
}