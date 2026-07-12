#include "distributions/Uni.h"
#include "algorithms/simulacion/aleatorio/AleatorioAlgorithms.h"

Uni::Uni(float a, float b) {
    if(a >= b){
        throw ParametroInvalidoException("Debe cumplirse a < b");
    }
    this->a = a;
    this->b = b;
}
Distribucion* Uni::clonar() const {
    return new Uni(*this);
};

float Uni::simular() const {
    return algorithms::simulacion::aleatorio::uniforme::generar(a, b);
}

float Uni::esperanza() const {
    return (a+b)/2;
}
float Uni::varianza() const {
    return ((b-a)*(b-a))/12;
}
float Uni::evaluar(float x) const {
    if(a < x && x < b){
        return 1/(b-a);
    }
    return 0;
}
float Uni::distribucionAcumulada(float x) const {
    if(x <= a){
        return 0;
    }
    if(a < x && x < b){
        return (x-a)/(b-a);
    }
    return 1;
}