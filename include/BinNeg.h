#ifndef BINNEG_H
#define BINNEG_H

#include "Distribucion.h"

class BinNeg: public Distribucion {
    private:
        int r;
        float p;
    public:
        float esperanza() const;
        float varianza() const;
        float desvio() const;
        float densidad(float) const;
        float distribucionAcumulada(float) const;
};

#endif