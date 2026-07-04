#include "Distribucion.h"

float Distribucion::desvio() const {
    return std::sqrt(varianza());
}