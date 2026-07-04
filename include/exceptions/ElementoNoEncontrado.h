#ifndef ELEMENTONOENCONTRADOEXCEPTION_H
#define ELEMENTONOENCONTRADOEXCEPTION_H

#include "DominioException.h"

class ElementoNoEncontradoException: public DominioException {
    public:
        explicit ElementoNoEncontradoException(const std::string& mensaje): DominioException(mensaje) {}
};

#endif