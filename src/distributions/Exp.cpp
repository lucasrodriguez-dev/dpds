#include "Exp.h"
#include "Uni.h"

Exp::Exp(float lambda) {
    if(lambda <= 0){
        throw ParametroInvalidoException("El parámetro lambda debe ser mayor que 0");
    }
    this->lambda = lambda;
}

float Exp::simular() const {
    return -std::log(Uni(0,1).simular())/lambda;
}

float Exp::esperanza() const {
    return 1/lambda;
}
float Exp::varianza() const {
    return 1/(lambda*lambda);
}
float Exp::evaluar(float x) const {
    if(x >= 0){
        return lambda*std::exp(-lambda*x);
    }
    return 0;
}
float Exp::distribucionAcumulada(float x) const {
    if(x >= 0){
        return 1 - std::exp(-lambda*x);
    }
    return 0;
}