#ifndef DTHIP_H
#define DTHIP_H

#include "DTDistribucion.h"

class DTHip: public DTDistribucion {
    private:
        int sampleSize;
        int totalSize;
        int distinguishedSize;
    public:
        DTHip(int,int,int);
        int getSampleSize() const;
        int getTotalSize() const;
        int getDistinguishedSize() const;
};

#endif