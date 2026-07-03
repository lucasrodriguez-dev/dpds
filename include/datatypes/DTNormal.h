#ifndef DTNORMAL_H
#define DTNORMAL_H

#include "DTDistribucion.h"

class DTNormal: public DTDistribucion {
    private:
        float mu;
        unsigned float sigmaSquare;
    public:
        DTNormal(float,float);
        int getMu() const;
        float getSigmaSquare() const;
};

#endif