#include "distributions/Pois.h"
#include "algorithms/poisson/PoissonAlgorithms.h"
#include "AleatorioAlgorithms.h"

Pois::Pois(float lambda) {
    if(lambda <= 0){
        throw ParametroInvalidoException("El parámetro lambda debe ser mayor que 0");
    }
    this->lambda = lambda;
}

float Pois::simular() const {
    //algoritmo de Knuth
    float L = std::exp(-lambda);
    float producto = 1;
    int uniformesGeneradas = 0;
    while(producto >= L){
        producto *= algorithms::simulacion::aleatorio::uniforme::generar(0,1);
        uniformesGeneradas++;
    }
    return uniformesGeneradas - 1;
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
    return algorithms::poisson::factorialFormula::pmf(lambda, x);
}
float Pois::distribucionAcumulada(float x) const {
    if(x < 0){
        return 0;
    }
    return algorithms::poisson::factorialFormula::cdf(lambda, x);
}