#ifndef DTEVENTO_H
#define DTEVENTO_H

class DTEvento {
    private:
        string nombre;
        float probabilidad;
    public:
        DTEvento(string,float);
        string getNombre() const;
        float getProbabilidad() const;
};

#endif