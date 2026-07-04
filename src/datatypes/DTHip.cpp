#include "DTHip.h"

DTHip::DTHip(int n,int N,int K) {
    this->sampleSize = n;
    this->totalSize = N;
    this->distinguishedSize = K;
}

int DTHip::getSampleSize() const {
    return sampleSize;
}
int DTHip::getTotalSize() const {
    return totalSize;
}
int DTHip::getDistinguishedSize() const {
    return distinguishedSize;
}