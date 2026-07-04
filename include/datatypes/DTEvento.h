#ifndef DTEVENTO_H
#define DTEVENTO_H

#include <string>

class DTEvento {
    private:
        std::string nombre;
        float probabilidad;
    public:
        DTEvento(std::string,float);
        std::string getNombre() const;
        float getProbabilidad() const;
};

#endif