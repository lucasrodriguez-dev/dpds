#include "Pois.h"
#include "PoissonAlgorithms.h"

Pois::Pois(float lambda) {
    if(lambda <= 0){
        throw ParametroInvalidoException("El parámetro lambda debe ser mayor que 0");
    }
    this->lambda = lambda;
}

float Pois::esperanza() const {
    return lambda;
}
float Pois::varianza() const {
    return lambda;
}
float Pois::evaluar(float x) const {
    if(x < 0 || std::floor(x) != x){
        return 0;
    }
    return algorithms::poisson::factorial::pmf(lambda, x);
}
float Pois::distribucionAcumulada(float x) const {
    if(x < 0){
        return 0;
    }
    return algorithms::poisson::factorial::cdf(lambda, x);
}