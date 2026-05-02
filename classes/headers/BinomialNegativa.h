#ifndef BINOMIALNEGATIVA_H
#define BINOMIALNEGATIVA_H

#include "Distribucion.h"

class BinomialNegativa: public Distribucion {
    private:
        int r; //>0
        float p; //0<=p<=1
    public:
        std::set<int> soporte();
};

#endif