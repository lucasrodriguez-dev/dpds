#ifndef DTBINNEG_H
#define DTBINNEG_H

#include "datatypes/DTDistribucion.h"

class DTBinNeg: public DTDistribucion {
    private:
        unsigned int r;
        float p;
    public:
        DTBinNeg(unsigned int,float);
        unsigned int getR() const;
        float getP() const;
};

#endif