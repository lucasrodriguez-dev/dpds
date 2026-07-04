#include "algorithms/aritmetica/factorial.h"

unsigned long long algorithms::aritmetica::factorial(unsigned int n) {
    if(n == 0){
        return 1;
    }
    return n*algorithms::aritmetica::factorial(n-1);
}