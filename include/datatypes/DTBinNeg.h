#ifndef DTBINNEG_H
#define DTBINNEG_H

#include "DTDistribucion.h"

class DTBinNeg: public DTDistribucion {
    private:
        int r;
        float p;
    public:
        DTBinNeg(int,float);
        int getR() const;
        float getP() const;
};

#endif