#ifndef BER_H
#define BER_H

#include "Distribucion.h"

class Ber: public Distribucion {
    private:
        float p;
    public:
        float esperanza() const;
        float varianza() const;
        float desvio() const;
        float densidad(float) const;
        float distribucionAcumulada(float) const;
};

#endif