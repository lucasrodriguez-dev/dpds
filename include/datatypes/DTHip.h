#ifndef DTHIP_H
#define DTHIP_H

#include "datatypes/DTDistribucion.h"

class DTHip: public DTDistribucion {
    private:
        unsigned int sampleSize;
        unsigned int totalSize;
        unsigned int distinguishedSize;
    public:
        DTHip(unsigned int n,unsigned int N,unsigned int K);
        unsigned int getSampleSize() const;
        unsigned int getTotalSize() const;
        unsigned int getDistinguishedSize() const;
};

#endif