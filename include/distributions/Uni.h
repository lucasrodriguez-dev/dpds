#ifndef UNI_H
#define UNI_H

#include "distributions/Distribucion.h"

class Uni: public Distribucion {
    private:
        float a;
        float b;
    public:
        Uni(float,float);
        float simular() const;
        float esperanza() const;
        float varianza() const;
        float evaluar(float) const;
        float distribucionAcumulada(float) const;
};

#endif