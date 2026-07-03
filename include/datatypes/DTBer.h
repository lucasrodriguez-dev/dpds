#ifndef DTBER_H
#define DTBER_H

#include "DTDistribucion.h"

class DTBer: public DTDistribucion {
    private:
        float p;
    public:
        DTBer(float);
        float getP() const;
};

#endif