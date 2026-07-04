#ifndef BIN_H
#define BIN_H

#include "Distribucion.h"

class Bin: public Distribucion {
    private:
        int n;
        float p;
    public:
        float esperanza() const;
        float varianza() const;
        float desvio() const;
        float densidad(float) const;
        float distribucionAcumulada(float) const;
};

#endif