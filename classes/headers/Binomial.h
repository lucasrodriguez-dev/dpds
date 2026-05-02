#ifndef BINOMIAL_H
#define BINOMIAL_H

#include "Distribucion.h"

class Binomial: public Distribucion {
    private:
        int n; //>0
        float p; //0<=p<=1
    public:
        std::set<int> soporte();
};

#endif