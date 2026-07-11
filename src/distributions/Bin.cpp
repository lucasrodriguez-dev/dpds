#include "distributions/Bin.h"
#include "algorithms/binomial/BinomialAlgorithms.h"
#include "distributions/Ber.h"

Bin::Bin(unsigned int n,float p) {
    if(p < 0 || p > 1){
        throw ParametroInvalidoException("La probabilidad debe pertenecer al unsigned intervalo [0,1]");
    }
    this->n = n;
    this->p = p;
}

float Bin::simular() const {
    int exitos = 0;
    for(int i=0; i<=n; i++){
        exitos += Ber(p).simular();
    }
    return exitos;
}

float Bin::esperanza() const {
    return n*p;
}
float Bin::varianza() const {
    return n*p*(1-p);
}
float Bin::evaluar(float x) const {
    if(x < 0 || std::floor(x) != x){
        return 0;
    }
    return algorithms::binomial::recurrencia::pmf(n, p, x);
}
float Bin::distribucionAcumulada(float x) const {
    if(x < 0){
        return 0;
    }
    return algorithms::binomial::recurrencia::cdf(n, p, x);
}