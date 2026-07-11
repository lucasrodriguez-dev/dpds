#ifndef DTPOIS_H
#define DTPOIS_H

#include "datatypes/DTDistribucion.h"

class DTPois: public DTDistribucion {
    private:
        float lambda;
    public:
        DTPois(float);
        float getLambda() const;
};

#endif