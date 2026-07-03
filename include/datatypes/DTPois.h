#ifndef DTPOIS_H
#define DTPOIS_H

#include "DTDistribucion.h"

class DTPois: public DTDistribucion {
    private:
        unsigned float lambda;
    public:
        DTPois(float);
        float getLambda() const;
};

#endif