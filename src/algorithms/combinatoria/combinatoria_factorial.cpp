#include "algorithms/aritmetica/factorial.h"
#include "algorithms/combinatoria/combinacion_factoriales.h"

using algorithms::aritmetica::factorial;

namespace algorithms::combinatoria::factoriales {
    unsigned long long combinacion(unsigned int n, unsigned int k) {
        return factorial(n)/(factorial(k)*factorial(n-k));
    }
}