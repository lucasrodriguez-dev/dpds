#include "factorial.h"
#include "combinacion_factorial.h"

unsigned long long algorithms::combinatoria::factorial::combinacion(unsigned int n, unsigned int k) {
    return algorithms::aritmetica::factorial(n)/(algorithms::aritmetica::factorial(k)*algorithms::aritmetica::factorial(n-k));
}