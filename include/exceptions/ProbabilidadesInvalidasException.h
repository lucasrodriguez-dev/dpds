#ifndef PROBABILIDADESINVALIDASEXCEPTION_H
#define PROBABILIDADESINVALIDASEXCEPTION_H

#include "exceptions/DominioException.h"

class ProbabilidadesInvalidasException: public DominioException {
    public:
        explicit ProbabilidadesInvalidasException(const std::string& mensaje): DominioException(mensaje) {}
};

#endif