#ifndef VAHANDLER_H
#define VAHANDLER_H

#include "VariableAleatoria.h"

class VAHandler {
    private:
        static VAHandler& instancia;
        VAHandler();
        std::set<VariableAleatoria> variablesAleatorias;
    public:
        VAHandler& getInstancia();
        bool exists(std::string);
        void add(VariableAleatoria);
};

#endif