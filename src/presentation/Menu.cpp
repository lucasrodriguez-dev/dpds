#include "presentation/Menu.h"
#include "factories/FabricaSistema.h"
#include "testing/CargaDatos.h"
#include <iostream>
#include "datatypes/DTBer.h"
#include "datatypes/DTBin.h"
#include "datatypes/DTHip.h"
#include "datatypes/DTBinNeg.h"
#include "datatypes/DTPois.h"
#include "datatypes/DTUni.h"
#include "datatypes/DTExp.h"
#include "datatypes/DTNormal.h"

using std::string, std::cout, std::cin, std::getline, std::endl, std::vector;

void Menu::mostrarMenu() {
    int opcion = -1;
    while (opcion != 10) {
        cout << "\n=== MENU PRINCIPAL ===" << endl;
        cout << "1. Crear experimento" << endl;
        cout << "2. Definir eventos" << endl;
        cout << "3. Simular experimento" << endl;
        cout << "4. Crear variable aleatoria" << endl;
        cout << "5. Simular variable aleatoria" << endl;
        cout << "6. Consultar propiedad de variable aleatoria" << endl;
        cout << "7. Evaluar variable aleatoria" << endl;
        cout << "8. Evaluar distribución acumulada de variable aleatoria" << endl;
        //cout << "9. Cargar Datos" << endl;
        cout << "10. Salir" << endl;
        cout << "Ingrese una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1: {
                crearExperimento();
                break;
            }
            case 2: {
                definirEventos();
                break;
            }
            case 3: {
                simularExperimento();
                break;
            }
            case 4: {
                crearVariableAleatoria();
                break;
            }
            case 5: {
                simularVariableAleatoria();
                break;
            }
            case 6: {
                consultarPropiedadNumerica();
                break;
            }
            case 7: {
                evaluarVariableAleatoria();
                break;
            }
            case 8: {
                evaluarFuncionDistribucionVariableAleatoria();
                break;
            }
            /*case 9: {
                cargarDatos();
                break;
            }
                */
            case 10: {
                cout << "Saliendo del sistema..." << endl;
                liberarMemoria();
                break;
            }
            default: {
                cout << "Opción inválida." << endl;
            }
        }
    }
}

struct seleccionExperimento {
    string nombre;
    bool existe;
};
struct seleccionVariable {
    string id;
    bool existe;
};

void listarExperimentos(vector<DTExperimento> experimentos){
    for(auto experimento: experimentos){
        cout << experimento << endl;
    }
}

void listarVariablesAleatorias(vector<DTVariableAleatoria> variables){
    for(auto variable: variables){
        cout << variable << endl;
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

seleccionVariable seleccionarVariable(vector<DTVariableAleatoria> variables){
    string id;
    cout << "Ingrese el id de la variable aleatoria a simular: "; getline(cin, id);
    bool existe = false;
    for(auto variable: variables){
        if(variable.getId() == id){
            existe = true;
            break;
        }
    }
    seleccionVariable retorno;
    retorno.existe = existe;
    retorno.id = id;
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

DTDistribucion* leerBernoulli() {
    float p;
    cout << "Ingrese la probabilidad de éxito: "; cin >> p;
    //validar p
    return new DTBer(p);
}
DTDistribucion* leerBinomial() {
    int n;
    float p;
    cout << "Ingrese la cantidad ensayos: "; cin >> n;
    cout << "Ingrese la probabilidad de éxito en cada ensayo: "; cin >> p;
    //validar n y p
    return new DTBin(n,p);
}
DTDistribucion* leerHipergeometrica() {
    int N;
    int K;
    int n;
    cout << "Ingrese el tamaño total de la población: "; cin >> N;
    cout << "Ingrese la cantidad de distinguidos: "; cin >> K;
    cout << "Ingrese el tamaño de la muestra: "; cin >> n;
    //validar n,N,K
    return new DTHip(n,N,K);
}
DTDistribucion* leerBinomialNegativa() {
    int r;
    float p;
    cout << "Ingrese la cantidad de éxitos: "; cin >> r;
    cout << "Ingrese la probabilidad de éxito: "; cin >> p;
    //validar r y p
    return new DTBinNeg(r,p);
}
DTDistribucion* leerPoisson() {
    float lambda;
    cout << "Ingrese el valor de λ: "; cin >> lambda;
    //validar lambda
    return new DTPois(lambda);
}
DTDistribucion* leerUniforme() {
    float a,b;
    cout << "Ingrese el valor del extremo inferior del intervalo: "; cin >> a;
    cout << "Ingrese el valor del extremo superior del intervalo: "; cin >> b;
    //validar a,b
    return new DTUni(a,b);
}
DTDistribucion* leerExponencial() {
    float lambda;
    cout << "Ingrese el valor de λ: "; cin >> lambda;
    //validar lambda
    return new DTExp(lambda);
}
DTDistribucion* leerNormal() {
    float mu, sigmaSquare;
    cout << "Ingrese el valor de μ: "; cin >> mu;
    cout << "Ingrese el valor de σ²: "; cin >> sigmaSquare;
    //validar mu y sigma
    return new DTNormal(mu, sigmaSquare);
}

void Menu::crearVariableAleatoria() {
    IExperimento* controlador = FabricaSistema::getInstancia()->getIExperimento();
    auto experimentos = controlador->listarExperimentos();
    listarExperimentos(experimentos);
    seleccionExperimento seleccion = seleccionarExperimento(experimentos);
    bool experimentoValido = seleccion.existe;
    if(experimentoValido) {
        string nombre = seleccion.nombre;
        string id;
        cout << "Ingrese id de la variable aleatoria: "; getline(cin, id);
        //validar que no exista la id
        string descripcion;
        int opcion;
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
        switch(opcion){
            case 1: {
                DTDistribucion* distribucion = leerBernoulli();
                controlador->altaVariableAleatoria(nombre, id, descripcion, *(distribucion));
                break;
            }
            case 2: {
                DTDistribucion* distribucion = leerBinomial();
                controlador->altaVariableAleatoria(nombre, id, descripcion, *(distribucion));
                break;
            }
            case 3: {
                DTDistribucion* distribucion = leerHipergeometrica();
                controlador->altaVariableAleatoria(nombre, id, descripcion, *(distribucion));
                break;
            }
            case 4: {
                DTDistribucion* distribucion = leerBinomialNegativa();
                controlador->altaVariableAleatoria(nombre, id, descripcion, *(distribucion));
                break;
            }
            case 5: {
                DTDistribucion* distribucion = leerPoisson();
                controlador->altaVariableAleatoria(nombre, id, descripcion, *(distribucion));
                break;
            }
            case 6: {
                DTDistribucion* distribucion = leerUniforme();
                controlador->altaVariableAleatoria(nombre, id, descripcion, *(distribucion));
                break;
            }
            case 7: {
                DTDistribucion* distribucion = leerExponencial();
                controlador->altaVariableAleatoria(nombre, id, descripcion, *(distribucion));
                break;
            }
            case 8: {
                DTDistribucion* distribucion = leerNormal();
                controlador->altaVariableAleatoria(nombre, id, descripcion, *(distribucion));
                break;
            }
            default: {
                cout << "Opción no válida";
                break;
            }
        }
    } else {
        cout << "Experimento no encontrado";
    }
}

void Menu::simularVariableAleatoria() {
    IExperimento* controlador = FabricaSistema::getInstancia()->getIExperimento();
    auto experimentos = controlador->listarExperimentos();
    listarExperimentos(experimentos);
    seleccionExperimento seleccion = seleccionarExperimento(experimentos);
    bool experimentoValido = seleccion.existe;
    if(experimentoValido) {
        string nombre = seleccion.nombre;
        auto variablesAleatorias = controlador->listarVariablesAleatorias(nombre);
        listarVariablesAleatorias(variablesAleatorias);
        seleccionVariable seleccionV = seleccionarVariable(variablesAleatorias);
        bool variableValida = seleccionV.existe;
        string id = seleccionV.id;
        if(variableValida){
            cout << "Valor simulado: " << controlador->simularVariableAleatoria(id) << endl;
        } else {
            cout << "Variable no encontrada" << endl;
        }
    } else {
        cout << "Experimento no encontrado";
    }
}

void Menu::consultarPropiedadNumerica() {
    IExperimento* controlador = FabricaSistema::getInstancia()->getIExperimento();
    auto experimentos = controlador->listarExperimentos();
    listarExperimentos(experimentos);
    seleccionExperimento seleccion = seleccionarExperimento(experimentos);
    bool experimentoValido = seleccion.existe;
    if(experimentoValido) {
        string nombre = seleccion.nombre;
        auto variablesAleatorias = controlador->listarVariablesAleatorias(nombre);
        listarVariablesAleatorias(variablesAleatorias);
        seleccionVariable seleccionV = seleccionarVariable(variablesAleatorias);
        bool variableValida = seleccionV.existe;
        string id = seleccionV.id;
        if(variableValida){
            int opcion;
            cout << "¿Qué propiedad desea consultar?: " << endl
            << "1. Esperanza" << endl
            << "2. Varianza" << endl 
            << "3. Desvío" << endl 
            << "Opción: "; cin >> opcion;
            switch(opcion){
                case 1: {
                    cout << "E(" << id << ") = " << controlador->consultarPropiedad(id, PropiedadNumerica::esperanza);
                    break;
                }
                case 2: {
                    cout << "V(" << id << ") = " << controlador->consultarPropiedad(id, PropiedadNumerica::varianza);
                    break;
                }
                case 3: {
                    cout << "σ(" << id << ") = " << controlador->consultarPropiedad(id, PropiedadNumerica::desvio);
                    break;
                }
                default: {
                    cout << "Opción no válida";
                    break;
                }
            }
        } else {
            cout << "Variable no encontrada" << endl;
        }
    } else {
        cout << "Experimento no encontrado";
    }
}

void Menu::evaluarVariableAleatoria() {
    IExperimento* controlador = FabricaSistema::getInstancia()->getIExperimento();
    auto experimentos = controlador->listarExperimentos();
    listarExperimentos(experimentos);
    seleccionExperimento seleccion = seleccionarExperimento(experimentos);
    bool experimentoValido = seleccion.existe;
    if(experimentoValido) {
        string nombre = seleccion.nombre;
        auto variablesAleatorias = controlador->listarVariablesAleatorias(nombre);
        listarVariablesAleatorias(variablesAleatorias);
        seleccionVariable seleccionV = seleccionarVariable(variablesAleatorias);
        bool variableValida = seleccionV.existe;
        string id = seleccionV.id;
        if(variableValida){
            float x;
            cout << "Ingrese en qué valor desea evaluar a " << id << ": " << endl; cin >> x;
            cout << "P(" << id << " = " << x << ") ≈ " << controlador->evaluarVariableAleatoria(id, x);
        } else {
            cout << "Variable no encontrada" << endl;
        }
    } else {
        cout << "Experimento no encontrado";
    }
}

void Menu::evaluarFuncionDistribucionVariableAleatoria() {
    IExperimento* controlador = FabricaSistema::getInstancia()->getIExperimento();
    auto experimentos = controlador->listarExperimentos();
    listarExperimentos(experimentos);
    seleccionExperimento seleccion = seleccionarExperimento(experimentos);
    bool experimentoValido = seleccion.existe;
    if(experimentoValido) {
        string nombre = seleccion.nombre;
        auto variablesAleatorias = controlador->listarVariablesAleatorias(nombre);
        listarVariablesAleatorias(variablesAleatorias);
        seleccionVariable seleccionV = seleccionarVariable(variablesAleatorias);
        bool variableValida = seleccionV.existe;
        string id = seleccionV.id;
        if(variableValida){
            float x;
            cout << "Ingrese en qué valor desea evaluar la distribución acumulada de " << id << ": " << endl; cin >> x;
            cout << "P(" << id << " ≤ " << x << ") ≈ " << controlador->evaluarFuncionDistribucionAcumulada(id, x);
        } else {
            cout << "Variable no encontrada" << endl;
        }
    } else {
        cout << "Experimento no encontrado";
    }
}