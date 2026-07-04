#ifndef DISTRIBUCION_H
#define DISTRIBUCION_H

#include "datatypes/DTDistribucion.h"

class Distribucion {
    public:
        Distribucion* crear(DTDistribucion);
        float simular() const;
        virtual float esperanza() const = 0;
        virtual float varianza() const = 0;
        virtual float desvio() const = 0;
        virtual float densidad(float) const = 0;
        virtual float distribucionAcumulada(float) const = 0;
};

#endif