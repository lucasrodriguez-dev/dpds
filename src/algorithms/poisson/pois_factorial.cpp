#include "pois_factorial.h"
#include "factorial.h"
#include <cmath>

float algorithms::poisson::factorial::pmf(float lambda, unsigned int k){
    return std::exp(-lambda)*std::pow(lambda, k)/algorithms::aritmetica::factorial(k);
}

float algorithms::poisson::factorial::cdf(float lambda, unsigned int k){
    int res = 0;
    for(int i = 0; i <= k; i++){
        res += algorithms::poisson::factorial::pmf(lambda, i);
    }
    return res;
}