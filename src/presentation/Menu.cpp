#include "Menu.h"
#include "FabricaSistema.h"
#include "CargaDatos.h"
#include <iostream>

using std::string, std::cout, std::cin, std::getline, std::endl, std::vector;

void Menu::liberarMemoria() {
    FabricaSistema::liberarMemoria();
    CargaDatos::liberarMemoria();
}

void Menu::crearExperimento() {
    string nombre, descripcion;
    cout << "Ingrese nombre del experimento: "; getline(cin, nombre);
    cout << "Ingrese descripción del experimento: "; getline(cin, descripcion);
    IExperimento* controlador = FabricaSistema::getInstancia()->getIExperimento();
    //validar que no exista experimento con ese nombre
    controlador->altaExperimento(nombre, descripcion);
    cout << "Experimento registrado exitosamente";
    delete controlador;
}

void Menu::definirEventos() {
    IExperimento* controlador = FabricaSistema::getInstancia()->getIExperimento();
    auto experimentos = controlador->listarExperimentos();
    for(auto experimento: experimentos){
        cout << endl << "nombre: " << experimento.getNombre() << endl;
        cout << "descripción: " << experimento.getDescripcion() << endl << "---";
    }
    string nombre;
    cout << "Ingrese nombre del experimento: "; getline(cin, nombre);
    bool experimentoValido = false;
    for(auto experimento: experimentos){
        if(experimento.getNombre() == nombre){
            experimentoValido = true;
            break;
        }
    }
    if(experimentoValido){
        vector<DTEvento> eventos;
        int agregarEvento = 1;
        float suma = 0;
        while(agregarEvento==1 && suma < 1){
            string nom; float prob;
            cout << endl << "=== Registrar evento ===" << endl;
            cout << "Ingrese evento: "; getline(cin, nom);
            cout << "Ingrese probabilidad: "; cin >> prob;
            suma += prob;
            //validar que no se repita y que esté entre 0 y 1
            eventos.push_back(DTEvento(nom, prob));
            cout << "Ingrese 1 si desea agregar otro evento, 0 si no: "; cin >> agregarEvento;
        }
        controlador->asociarEventos(nombre, eventos);
    } else {
        cout << "El nombre del experimento no es válido";        
    }
    delete controlador;
}

void Menu::simularExperimento() {
    IExperimento* controlador = FabricaSistema::getInstancia()->getIExperimento();
    auto experimentos = controlador->listarExperimentos();
    for(auto experimento: experimentos){
        cout << endl << "nombre: " << experimento.getNombre() << endl;
        cout << "descripción: " << experimento.getDescripcion() << endl << "---" << endl;
    }
    string nombre;
    cout << "Ingrese nombre del experimento: "; getline(cin, nombre);
    bool experimentoValido = false;
    for(auto experimento: experimentos){
        if(experimento.getNombre() == nombre){
            experimentoValido = true;
            break;
        }
    }
    if(experimentoValido){
        DTEvento eventoSimulado = controlador->simularExperimento(nombre);
        cout << "Evento simulado: " << eventoSimulado.getNombre() << endl;
    } else {
        cout << "El nombre del experimento no es válido" << endl;        
    }
    delete controlador;  
}

void Menu::realizarMultiplesSimulaciones() {
    IExperimento* controlador = FabricaSistema::getInstancia()->getIExperimento();
    auto experimentos = controlador->listarExperimentos();
    for(auto experimento: experimentos){
        cout << endl << "nombre: " << experimento.getNombre() << endl;
        cout << "descripción: " << experimento.getDescripcion() << endl << "---" << endl;
    }
    string nombre;
    cout << "Ingrese nombre del experimento: "; getline(cin, nombre);
    bool experimentoValido = false;
    for(auto experimento: experimentos){
        if(experimento.getNombre() == nombre){
            experimentoValido = true;
            break;
        }
    }
    if(experimentoValido){
        int cantidad;
        cout << "Ingrese cantidad de simulaciones: "; cin >> cantidad;
        if(cantidad <= 0){
            cout << "La cantidad de simulaciones debe ser mayor que 0";
        } else {
            vector<DTSimulacionExperimento> simulados = controlador->simularExperimento(nombre, cantidad);
            for(auto simulado: simulados){
                cout << simulado << endl;
            }
        }
    } else {
        cout << "El nombre del experimento no es válido" << endl;        
    }
    delete controlador;  
}