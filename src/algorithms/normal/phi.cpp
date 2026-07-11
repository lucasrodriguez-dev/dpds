#include "algorithms/normal/phi.h"
#include <cmath>

namespace algorithms::normal {
    float phi(float x){
        return 0.5*(1+std::erf(x/std::sqrt(2)));
    }
}