#include "Menu.h"
#include "FabricaSistema.h"
#include "CargaDatos.h"
#include <iostream>
#include "DTBer.h"
#include "DTBin.h"

using std::string, std::cout, std::cin, std::getline, std::endl, std::vector;

struct seleccionExperimento {
    string nombre;
    bool existe;
};

void listarExperimentos(vector<DTExperimento> experimentos){
    for(auto experimento: experimentos){
        cout << experimento << endl;
    }
}

seleccionExperimento seleccionarExperimento(vector<DTExperimento> experimentos){
    string nombre;
    cout << "Ingrese nombre del experimento: "; getline(cin, nombre);
    bool existe = false;
    for(auto experimento: experimentos){
        if(experimento.getNombre() == nombre){
            existe = true;
            break;
        }
    }
    seleccionExperimento retorno;
    retorno.existe = existe;
    retorno.nombre = nombre;
    return retorno;
}

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
    listarExperimentos(experimentos);
    seleccionExperimento seleccion = seleccionarExperimento(experimentos);
    bool experimentoValido = seleccion.existe;
    string nombre = seleccion.nombre; 
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
    listarExperimentos(experimentos);
    seleccionExperimento seleccion = seleccionarExperimento(experimentos);
    bool experimentoValido = seleccion.existe;
    string nombre = seleccion.nombre; 
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
    listarExperimentos(experimentos);
    seleccionExperimento seleccion = seleccionarExperimento(experimentos);
    bool experimentoValido = seleccion.existe;
    string nombre = seleccion.nombre;
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

void Menu::crearVariableAleatoria() {
    IExperimento* controlador = FabricaSistema::getInstancia()->getIExperimento();
    auto experimentos = controlador->listarExperimentos();
    listarExperimentos(experimentos);
    seleccionExperimento seleccion = seleccionarExperimento(experimentos);
    bool experimentoValido = seleccion.existe;
    string nombre = seleccion.nombre;
    string id;
    cout << "Ingrese id de la variable aleatoria: "; getline(cin, id);
    //validar que no exista la id
    string descripcion;
    int opcion;
    DTDistribucion* distribucion;
    cout << "Ingrese descripción de la variable aleatoria: "; getline(cin, descripcion);
    cout << "Ingrese su distribución: " << endl 
    << "1. Bernoulli" << endl
    << "2. Binomial" << endl 
    << "3. Hipergeométrica" << endl 
    << "4. Binomial negativa" << endl 
    << "5. Poisson" << endl 
    << "6. Uniforme" << endl 
    << "7. Exponencial" << endl 
    << "8. Normal" << endl
    << "Opción: "; cin >> opcion;
    if(opcion == 1){
        float p;
        cout << "Ingrese la probabilidad de éxito: "; cin >> p;
        //validar p
        distribucion = new DTBer(p);
        controlador->altaVariableAleatoria(nombre, id, descripcion, *(distribucion));
    }
    if(opcion == 2){
        int n;
        float p;
        cout << "Ingrese la cantidad ensayos: "; cin >> n;
        cout << "Ingrese la probabilidad de éxito en cada ensayo: "; cin >> p;
        //validar n y p
        distribucion = new DTBin(n,p);
        controlador->altaVariableAleatoria(nombre, id, descripcion, *(distribucion));
    }
}