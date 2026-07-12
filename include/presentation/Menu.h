#ifndef MENU_H
#define MENU_H

#include <string>

class Menu {
private:
    void crearExperimento();
    void definirEventos();
    void simularExperimento();
    void realizarMultiplesSimulaciones();
    void crearVariableAleatoria();
    void simularVariableAleatoria();
    void consultarPropiedadNumerica();
    void evaluarVariableAleatoria();
    void evaluarFuncionDistribucionVariableAleatoria();
    //void cargarDatos();
    void liberarMemoria();
public:
    void mostrarMenu();
};

#endif