#ifndef BER_H
#define BER_H

#include "distributions/Distribucion.h"

class Ber: public Distribucion {
    private:
        float p;
    public:
        Ber(float);
        float simular() const;
        float esperanza() const;
        float varianza() const;
        float evaluar(float) const;
        float distribucionAcumulada(float) const;
};

#endif