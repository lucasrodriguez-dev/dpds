#ifndef NORMAL_H
#define NORMAL_H

#include "Distribucion.h"

class Normal: public Distribucion {
    private:
        float mu;
        float sigmaSquare;
    public:
        Normal(float,float);
        float esperanza() const;
        float varianza() const;
        float evaluar(float) const;
        float distribucionAcumulada(float) const;
};

#endif