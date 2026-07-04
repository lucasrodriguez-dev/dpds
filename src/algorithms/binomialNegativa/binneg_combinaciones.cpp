#include "binneg_combinaciones.h"
#include "combinacion_factorial.h"
#include <cmath>

float algorithms::binomialnegativa::combinaciones::pmf(unsigned int r, float p, unsigned int k){
    return algorithms::combinatoria::factorial::combinacion(k-1,r-1)*std::pow(p,r)*std::pow(1-p,k-r);
}

float algorithms::binomialnegativa::combinaciones::cdf(unsigned int r, float p, unsigned int k){
    int res = 0;
    for(int i = 0; i <= k; i++){
        res += algorithms::binomialnegativa::combinaciones::pmf(r, p, i);
    }
    return res;
}