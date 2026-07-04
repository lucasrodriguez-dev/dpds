#ifndef HIP_H
#define HIP_H

#include "Distribucion.h"

class Hip: public Distribucion {
    private:
        int sampleSize;
        int totalSize;
        int distinguishedSize;
    public:
        float esperanza() const;
        float varianza() const;
        float desvio() const;
        float evaluar(float) const;
        float distribucionAcumulada(float) const;
};

#endif