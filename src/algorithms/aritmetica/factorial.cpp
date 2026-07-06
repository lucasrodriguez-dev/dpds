#include "algorithms/aritmetica/factorial.h"

namespace algorithms::aritmetica {
    unsigned long long factorial(unsigned int n) {
        if(n == 0){
            return 1;
        }
        return n*factorial(n-1);
    }
}
