#include "pois_factorialFormula.h"
#include "factorial.h"
#include <cmath>

using algorithms::aritmetica::factorial;
using std::pow;
using std::exp;

namespace algorithms::poisson::factorialFormula {
    float pmf(float lambda, unsigned int k){
        return exp(-lambda)*pow(lambda, k)/factorial(k);
    }

    float cdf(float lambda, unsigned int k){
        int res = 0;
        for(int i = 0; i <= k; i++){
            res += pmf(lambda, i);
        }
        return res;
    }
}