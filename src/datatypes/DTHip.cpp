#include "DTHip.h"

DTHip::DTHip(unsigned int n,unsigned int N,unsigned int K) {
    if(n > N || K > N){
        throw ParametroInvalidoException("Tanto el tamaño de la muestra como la cantidad de distinguidos deben ser menores o iguales que la población total");
    }
    this->sampleSize = n;
    this->totalSize = N;
    this->distinguishedSize = K;
}

unsigned int DTHip::getSampleSize() const {
    return sampleSize;
}
unsigned int DTHip::getTotalSize() const {
    return totalSize;
}
unsigned int DTHip::getDistinguishedSize() const {
    return distinguishedSize;
}