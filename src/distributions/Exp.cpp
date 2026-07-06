#include "Exp.h"

Exp::Exp(float) {}

float Exp::simular() const {}

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