#ifndef DTBIN_H
#define DTBIN_H

#include "DTDistribucion.h"

class DTBin: public DTDistribucion {
    private:
        unsigned int n;
        float p;
    public:
        DTBin(unsigned int,float);
        unsigned int getN() const;
        float getP() const;
};

#endif