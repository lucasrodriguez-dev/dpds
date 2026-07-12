#ifndef DTUNI_H
#define DTUNI_H

#include "datatypes/DTDistribucion.h"

class DTUni: public DTDistribucion {
    private:
        float a;
        float b;
    public:
        DTUni(float,float);
        float getA() const;
        float getB() const;
};

#endif