#ifndef DTEXP_H
#define DTEXP_H

#include "DTDistribucion.h"

class DTExp: public DTDistribucion {
    private:
        float lambda;
    public:
        DTExp(float);
        float getLambda() const;
};

#endif