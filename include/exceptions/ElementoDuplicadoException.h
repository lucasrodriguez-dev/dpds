#ifndef ELEMENTODUPLICADOEXCEPTION_H
#define ELEMENTODUPLICADOEXCEPTION_H

#include "DominioException.h"

class ElementoDuplicadoException: public DominioException {
    public:
        explicit ElementoDuplicadoException(const std::string& mensaje): DominioException(mensaje) {}
};

#endif