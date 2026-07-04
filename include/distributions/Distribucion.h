#ifndef DISTRIBUCION_H
#define DISTRIBUCION_H

#include "datatypes/DTDistribucion.h"
#include <cmath>

class Distribucion {
    public:
        virtual ~Distribucion() = default;
        Distribucion* crear(DTDistribucion);
        float simular() const;
        virtual float esperanza() const = 0;
        virtual float varianza() const = 0;
        float desvio() const;
        virtual float evaluar(float) const = 0;
        virtual float distribucionAcumulada(float) const = 0;
};

#endif