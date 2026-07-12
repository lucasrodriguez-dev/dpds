#ifndef DISTRIBUCION_H
#define DISTRIBUCION_H

#include <cmath>
#include "exceptions/TipoDistribucionInvalidaException.h"
#include "exceptions/ParametroInvalidoException.h"

class Distribucion {
    public:
        virtual ~Distribucion() = default;
        virtual float simular() const = 0;
        virtual float esperanza() const = 0;
        virtual float varianza() const = 0;
        float desvio() const;
        virtual float evaluar(float) const = 0;
        virtual float distribucionAcumulada(float) const = 0;
};

#endif