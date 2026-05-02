#ifndef EMPIRICA_H
#define EMPIRICA_H

#include "Distribucion.h"

struct ValorProbabilidad {
    int valor;
    float probabilidad; //0<=probabilidad<=1
};

class Empirica: public Distribucion {
    private:
        std::set<ValorProbabilidad> valores;
    public:
        std::set<int> soporte();
};

#endif