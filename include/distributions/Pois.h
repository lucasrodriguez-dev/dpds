#ifndef POIS_H
#define POIS_H

#include "Distribucion.h"

class Pois: public Distribucion {
    private:
        float lambda;
    public:
        Pois(float);
        float esperanza() const;
        float varianza() const;
        float evaluar(float) const;
        float distribucionAcumulada(float) const;
};

#endif