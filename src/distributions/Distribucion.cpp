#include "distributions/Distribucion.h"

float Distribucion::desvio() const {
    return std::sqrt(varianza());
}