#ifndef HIPERGEOMETRICA_H
#define HIPERGEOMETRICA_H

#include "Distribucion.h"

class Hipergeometrica: public Distribucion {
    private:
        int n; //>0
        int N; //>0
        int K; //>0
    public:
        std::set<int> soporte();
};

#endif