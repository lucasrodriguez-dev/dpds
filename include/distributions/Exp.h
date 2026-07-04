#ifndef EXP_H
#define EXP_H

#include "Distribucion.h"

class Exp: public Distribucion {
    private:
        float lambda;
    public:
        float esperanza() const;
        float varianza() const;
        float desvio() const;
        float evaluar(float) const;
        float distribucionAcumulada(float) const;
};

#endif