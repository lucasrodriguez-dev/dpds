#ifndef DISTRIBUCION_H
#define DISTRIBUCION_H

#include <set>

class Distribucion {
    public:
        virtual std::set<int> soporte() = 0;
};

#endif