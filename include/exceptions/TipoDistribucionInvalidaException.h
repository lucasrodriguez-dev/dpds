#ifndef TIPODISTRIBUCIONINVALIDAEXCEPTION_H
#define TIPODISTRIBUCIONINVALIDAEXCEPTION_H

#include "exceptions/DominioException.h"

class TipoDistribucionInvalidaException: public DominioException {
    public:
        explicit TipoDistribucionInvalidaException(const std::string& mensaje): DominioException(mensaje) {}
};

#endif