#ifndef DTEXPERIMENTO_H
#define DTEXPERIMENTO_H

class DTExperimento {
    private:
        string nombre;
        string descripcion;
    public:
        DTExperimento(string,string);
        string getNombre() const;
        string getDescripcion() const;
};

#endif