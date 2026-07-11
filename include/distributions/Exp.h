#ifndef EXP_H
#define EXP_H

#include "distributions/Distribucion.h"

class Exp: public Distribucion {
    private:
        float lambda;
    public:
        Exp(float);
        float simular() const;
        float esperanza() const;
        float varianza() const;
        float evaluar(float) const;
        float distribucionAcumulada(float) const;
};

#endif