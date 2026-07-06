#ifndef PROBABILIDADESINVALIDASEXCEPTION_H
#define PROBABILIDADESINVALIDASEXCEPTION_H

#include "DominioException.h"

class ProbabilidadesInvalidasException: public DominioException {
    public:
        explicit ProbabilidadesInvalidasException(const std::string& mensaje): DominioException(mensaje) {}
};

#endif