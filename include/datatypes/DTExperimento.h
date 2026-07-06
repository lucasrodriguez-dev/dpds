#ifndef DTEXPERIMENTO_H
#define DTEXPERIMENTO_H

#include <string>

class DTExperimento {
    private:
        std::string nombre;
        std::string descripcion;
    public:
        DTExperimento(std::string,std::string);
        std::string getNombre() const;
        std::string getDescripcion() const;
};
std::ostream& operator<<(std::ostream&, DTExperimento);

#endif