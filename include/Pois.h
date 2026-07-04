#ifndef POIS_H
#define POIS_H

#include "Distribucion.h"

class Pois: public Distribucion {
    private:
        float lambda;
    public:
        float esperanza() const;
        float varianza() const;
        float desvio() const;
        float densidad(float) const;
        float distribucionAcumulada(float) const;
};

#endif