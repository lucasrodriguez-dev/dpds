#ifndef PARAMETROINVALIDOEXCEPTION_H
#define PARAMETROINVALIDOEXCEPTION_H

#include "exceptions/DominioException.h"

class ParametroInvalidoException: public DominioException {
    public:
        explicit ParametroInvalidoException(const std::string& mensaje): DominioException(mensaje) {}
};

#endif