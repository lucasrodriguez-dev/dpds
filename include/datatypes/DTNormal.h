#ifndef DTNORMAL_H
#define DTNORMAL_H

#include "DTDistribucion.h"

class DTNormal: public DTDistribucion {
    private:
        float mu;
        float sigmaSquare;
    public:
        DTNormal(float,float);
        float getMu() const;
        float getSigmaSquare() const;
};

#endif