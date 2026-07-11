#ifndef BINNEG_H
#define BINNEG_H

#include "distributions/Distribucion.h"

class BinNeg: public Distribucion {
    private:
        int r;
        float p;
    public:
        BinNeg(int,float);
        float simular() const;
        float esperanza() const;
        float varianza() const;
        float evaluar(float) const;
        float distribucionAcumulada(float) const;
};

#endif