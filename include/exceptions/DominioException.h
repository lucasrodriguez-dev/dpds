#ifndef DOMINIOEXCEPTION_H
#define DOMINIOEXCEPTION_H

#include <stdexcept>
#include <string>

class DominioException: public std::runtime_error {
    public:
        explicit DominioException(const std::string& mensaje): std::runtime_error(mensaje) {}
};

#endif