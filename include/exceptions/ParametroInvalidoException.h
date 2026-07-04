#ifndef PARAMETROINVALIDOEXCEPTION_H
#define PARAMETROINVALIDOEXCEPTION_H

#include "DominioException.h"

class ParametroInvalidoException: public DominioException {
    public:
        explicit ParametroInvalidoException(const std::string& mensaje): DominioException(mensaje) {}
};

#endif