#ifndef DTVARIABLEALEATORIA_H
#define DTVARIABLEALEATORIA_H

#include <string>

class DTVariableAleatoria {
    private:
        std::string id;
        std::string descripcion;
    public:
        DTVariableAleatoria(std::string,std::string);
        std::string getId() const;
        std::string getDescripcion() const;
};
std::ostream& operator<<(std::ostream&, DTVariableAleatoria);

#endif