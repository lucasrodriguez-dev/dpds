#ifndef NORMAL_H
#define NORMAL_H

#include "Distribucion.h"

class Normal: public Distribucion {
    private:
        float mu;
        float sigmaSquare;
    public:
        float esperanza() const;
        float varianza() const;
        float desvio() const;
        float evaluar(float) const;
        float distribucionAcumulada(float) const;
};

#endif