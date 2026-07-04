#include "Hip.h"
#include "HipergeometricaAlgorithms.h"

Hip::Hip(unsigned int n, unsigned int N,unsigned int K) {
    if(n > N || K > N){
        throw ParametroInvalidoException("Tanto el tamaño de la muestra como la cantidad de distinguidos deben ser menores o iguales que la población total");
    }
    this->sampleSize = n;
    this->totalSize = N;
    this->distinguishedSize = K;
}

float Hip::esperanza() const {
    return sampleSize*distinguishedSize/totalSize;
}
float Hip::varianza() const {
    return (sampleSize*distinguishedSize/totalSize)*(1-distinguishedSize/totalSize)*(totalSize-sampleSize)/(totalSize-1);
}
float Hip::evaluar(float x) const {
    if(x < 0 || std::floor(x) != x){
        return 0;
    }
    return algorithms::hipergeometrica::combinaciones::pmf(sampleSize, totalSize, distinguishedSize, x);
}
float Hip::distribucionAcumulada(float x) const {
    if(x < 0){
        return 0;
    }
    return algorithms::hipergeometrica::combinaciones::cdf(sampleSize, totalSize, distinguishedSize, x);
}