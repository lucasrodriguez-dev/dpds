#ifndef UNI_H
#define UNI_H

#include "Distribucion.h"

class Uni: public Distribucion {
    private:
        float a;
        float b;
    public:
        float esperanza() const;
        float varianza() const;
        float evaluar(float) const;
        float distribucionAcumulada(float) const;
};

#endif