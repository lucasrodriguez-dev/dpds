#ifndef DTVARIABLEALEATORIA_H
#define DTVARIABLEALEATORIA_H

class DTVariableAleatoria {
    private:
        string id;
        string descripcion;
    public:
        DTVariableAleatoria(string,string);
        string getId() const;
        string getDescripcion() const;
};

#endif