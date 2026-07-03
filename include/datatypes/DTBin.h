#ifndef DTBIN_H
#define DTBIN_H

#include "DTDistribucion.h"

class DTBin: public DTDistribucion {
    private:
        int n;
        float p;
    public:
        DTBin(int,float);
        int getN() const;
        float getP() const;
};

#endif