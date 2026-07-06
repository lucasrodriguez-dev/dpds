#include "BinNeg.h"
#include "BinomialNegativaAlgorithms.h"
#include "Ber.h"

BinNeg::BinNeg(int r, float p) {
    if(r < 1){
        throw ParametroInvalidoException("La cantidad de éxitos debe ser mayor o igual que 1");
    }
    if(p < 0 || p > 1){
        throw ParametroInvalidoException("La probabilidad debe pertenecer al intervalo [0,1]");
    }
    this->r = r;
    this->p = p;
}

float BinNeg::simular() const {
    int exitos = 0;
    int pruebas = 0;
    while(exitos < r){
        exitos += Ber(p).simular();
        pruebas++;
    }
    return pruebas;
}

float BinNeg::esperanza() const {
    return r/p;
}
float BinNeg::varianza() const {
    return r*(1-p)/(p*p);
}
float BinNeg::evaluar(float x) const {
    if(x < r || std::floor(x) != x){
        return 0;
    }
    return algorithms::binomialnegativa::combinaciones::pmf(r, p, x);
}
float BinNeg::distribucionAcumulada(float x) const {
    if(x < r){
        return 0;
    }
    return algorithms::binomialnegativa::combinaciones::cdf(r, p, x);
}