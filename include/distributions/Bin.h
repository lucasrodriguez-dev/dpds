#ifndef BIN_H
#define BIN_H

#include "distributions/Distribucion.h"

class Bin: public Distribucion {
    private:
        unsigned int n;
        float p;
    public:
        Bin(unsigned int,float);
        Distribucion* clonar() const;
        float simular() const;
        float esperanza() const;
        float varianza() const;
        float evaluar(float) const;
        float distribucionAcumulada(float) const;
};

#endif