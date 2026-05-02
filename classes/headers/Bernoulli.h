#ifndef BERNOULLI_H
#define BERNOULLI_H

#include "Distribucion.h"

class Bernoulli: public Distribucion {
    private:
        float p; //0<=p<=1
    public:
        std::set<int> soporte();
};

#endif