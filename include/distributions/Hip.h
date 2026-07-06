#ifndef HIP_H
#define HIP_H

#include "Distribucion.h"

class Hip: public Distribucion {
    private:
        unsigned int sampleSize;
        unsigned int totalSize;
        unsigned int distinguishedSize;
    public:
        Hip(unsigned int n,unsigned int N,unsigned int K);
        float simular() const;
        float esperanza() const;
        float varianza() const;
        float evaluar(float) const;
        float distribucionAcumulada(float) const;
};

#endif