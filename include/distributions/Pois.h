#ifndef POIS_H
#define POIS_H

#include "distributions/Distribucion.h"

class Pois: public Distribucion {
    private:
        float lambda;
    public:
        Pois(float);
        float simular() const;
        float esperanza() const;
        float varianza() const;
        float evaluar(float) const;
        float distribucionAcumulada(float) const;
};

#endif