#include "distributions/Hip.h"
#include "algorithms/hipergeometrica/HipergeometricaAlgorithms.h"
#include "distributions/Ber.h"

using algorithms::hipergeometrica::combinaciones::pmf;
using algorithms::hipergeometrica::combinaciones::cdf;

Hip::Hip(unsigned int n, unsigned int N,unsigned int K) {
    if(n > N || K > N){
        throw ParametroInvalidoException("Tanto el tamaño de la muestra como la cantidad de distinguidos deben ser menores o iguales que la población total");
    }
    this->sampleSize = n;
    this->totalSize = N;
    this->distinguishedSize = K;
}

float Hip::simular() const {
    int distinguidosExtraidos = 0;
    int totalRestante = totalSize;
    int distinguidosRestantes = distinguishedSize;
    for(size_t i=0; i<sampleSize; i++){
        float probabilidadDistinguido = distinguidosRestantes/totalRestante;
        Ber esDistinguido(probabilidadDistinguido);
        if(esDistinguido.simular() == 1){
            distinguidosExtraidos++;
            distinguidosRestantes--;
        }
        totalRestante--;
    }
    return distinguidosExtraidos;
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
    return pmf(sampleSize, totalSize, distinguishedSize, x);
}
float Hip::distribucionAcumulada(float x) const {
    if(x < 0){
        return 0;
    }
    return cdf(sampleSize, totalSize, distinguishedSize, x);
}