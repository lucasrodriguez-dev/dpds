#ifndef MENU_H
#define MENU_H

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