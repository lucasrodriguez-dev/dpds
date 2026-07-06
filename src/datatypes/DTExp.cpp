#include "DTExp.h"

DTExp::DTExp(float lambda) {
    if(lambda <= 0){
        throw ParametroInvalidoException("El parámetro lambda debe ser mayor que 0");
    }
    this->lambda = lambda;
}

float DTExp::getLambda() const {
    return lambda;
}