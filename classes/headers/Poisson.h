#ifndef POISSON_H
#define POISSON_H

#include "Distribucion.h"

class Poisson: public Distribucion {
    private:
        float lambda; //>0
    public:
        std::set<int> soporte();
};

#endif