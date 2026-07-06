#include "DTPois.h"

DTPois::DTPois(float lambda) {
    if(lambda <= 0){
        throw ParametroInvalidoException("El parámetro lambda debe ser mayor que 0");
    }
    this->lambda = lambda;
}

float DTPois::getLambda() const {
    return lambda;
}