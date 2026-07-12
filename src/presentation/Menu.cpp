#include "presentation/Menu.h"
#include "factories/FabricaSistema.h"
#include "testing/CargaDatos.h"
#include "presentation/EntradaAlgorithms.h"
#include <iostream>
#include "datatypes/DTBer.h"
#include "datatypes/DTBin.h"
#include "datatypes/DTHip.h"
#include "datatypes/DTBinNeg.h"
#include "datatypes/DTPois.h"
#include "datatypes/DTUni.h"
#include "datatypes/DTExp.h"
#include "datatypes/DTNormal.h"

using std::string, std::cout, std::cin, std::getline, std::endl, std::vector, std::stringstream;
using presentacion::algorithms::entrada::descartarSaltoDeLinea;
using presentacion::algorithms::entrada::esVacio;
using presentacion::algorithms::entrada::leerBooleano;
using presentacion::algorithms::entrada::leerDecimal;
using presentacion::algorithms::entrada::leerDecimalPositivo;
using presentacion::algorithms::entrada::leerEntero;
using presentacion::algorithms::entrada::leerEnteroPositivo;
using presentacion::algorithms::entrada::leerNoVacio;
using presentacion::algorithms::entrada::leerProbabilidad;

void listarExperimentos(vector<DTExperimento> experimentos){
    cout << endl << "EXPERIMENTOS" << endl << ".............." << endl;
    for(auto experimento: experimentos){
        cout << experimento << endl;
    }
    cout << ".............." << endl;
}

void listarVariablesAleatorias(vector<DTVariableAleatoria> variables){
    for(auto variable: variables){
        cout << variable << endl;
    }
}

DTDistribucion* leerBernoulli() {
    float p = leerProbabilidad("Ingrese la probabilidad de éxito: ");
    return new DTBer(p);
}
DTDistribucion* leerBinomial() {
    unsigned int n = leerEnteroPositivo("Ingrese la cantidad de ensayos: ");
    float p = leerProbabilidad("Ingrese la probabilidad de éxito en cada ensayo: ");
    return new DTBin(n,p);
}
DTDistribucion* leerHipergeometrica() {
    int N = leerEnteroPositivo("Ingrese el tamaño total de la población: ");
    int K = leerEnteroPositivo("Ingrese la cantidad de distinguidos: ");
    int n = leerEnteroPositivo("Ingrese el tamaño de la muestra: ");
    return new DTHip(n,N,K);
}
DTDistribucion* leerBinomialNegativa() {
    int r = leerEnteroPositivo("Ingrese la cantidad de éxitos: ");
    float p = leerProbabilidad("Ingrese la probabilidad de éxito: ");
    return new DTBinNeg(r,p);
}
DTDistribucion* leerPoisson() {
    float lambda = leerDecimalPositivo("Ingrese el valor de λ: ");
    return new DTPois(lambda);
}
DTDistribucion* leerUniforme() {
    float a,b;
    a = b = 0;
    while(a == b){
        cout << "(Los extremos del intervalo deben ser distintos)" << endl;
        float a = leerDecimal("Ingrese un extremo del intervalo: ");
        float b = leerDecimal("Ingrese el otro extremo: ");
    }
    if (b < a)
        return new DTUni(b,a);
    return new DTUni(a,b);
}
DTDistribucion* leerExponencial() {
    float lambda = leerDecimalPositivo("Ingrese el valor de λ: ");
    return new DTExp(lambda);
}
DTDistribucion* leerNormal() {
    float mu = leerDecimal("Ingrese el valor de μ: ");
    float sigmaSquare = leerDecimalPositivo("Ingrese el valor de σ²: ");
    return new DTNormal(mu, sigmaSquare);
}
DTDistribucion* leerDistribucion(string mensaje) {
    while(true) {
        cout << mensaje << endl 
            << "1. Bernoulli" << endl
            << "2. Binomial" << endl 
            << "3. Hipergeométrica" << endl 
            << "4. Binomial negativa" << endl 
            << "5. Poisson" << endl 
            << "6. Uniforme" << endl 
            << "7. Exponencial" << endl 
            << "8. Normal" << endl;
        int opcion = leerEntero("Opción: ");
        switch(opcion){
            case 1: {
                DTDistribucion* distribucion = leerBernoulli();
                return distribucion;
            }
            case 2: {
                DTDistribucion* distribucion = leerBinomial();
                return distribucion;
            }
            case 3: {
                DTDistribucion* distribucion = leerHipergeometrica();
                return distribucion;
            }
            case 4: {
                DTDistribucion* distribucion = leerBinomialNegativa();
                return distribucion;
            }
            case 5: {
                DTDistribucion* distribucion = leerPoisson();
                return distribucion;
            }
            case 6: {
                DTDistribucion* distribucion = leerUniforme();
                return distribucion;
            }
            case 7: {
                DTDistribucion* distribucion = leerExponencial();
                return distribucion;
            }
            case 8: {
                DTDistribucion* distribucion = leerNormal();
                return distribucion;
            }
            default: {
                cout << "Opción no válida.";
                break;
            }
        }
    }
}

void Menu::mostrarMenu() {
    int opcion = -1;
    while (opcion != 0) {
        cout << endl << "=== MENU PRINCIPAL ===" << endl;
        cout << "1. Crear experimento" << endl;
        cout << "2. Definir eventos" << endl;
        cout << "3. Simular experimento" << endl;
        cout << "4. Realizar múltiples simulaciones" << endl;
        cout << "5. Crear variable aleatoria" << endl;
        cout << "6. Simular variable aleatoria" << endl;
        cout << "7. Consultar propiedad de variable aleatoria" << endl;
        cout << "8. Evaluar variable aleatoria" << endl;
        cout << "9. Evaluar distribución acumulada de variable aleatoria" << endl;
        //cout << "10. Cargar Datos" << endl;
        cout << "0. Salir" << endl;
        cout << "Ingrese una opcion: ";
        cin >> opcion; descartarSaltoDeLinea();
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
                realizarMultiplesSimulaciones();
                break;
            }
            case 5: {
                crearVariableAleatoria();
                break;
            }
            case 6: {
                simularVariableAleatoria();
                break;
            }
            case 7: {
                consultarPropiedadNumerica();
                break;
            }
            case 8: {
                evaluarVariableAleatoria();
                break;
            }
            case 9: {
                evaluarFuncionDistribucionVariableAleatoria();
                break;
            }
            /*case 10: {
                cargarDatos();
                break;
            }
                */
            case 0: {
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

void Menu::crearExperimento() {
    IExperimento* controlador = FabricaSistema::getInstancia()->getIExperimento();
    while(true){
        string nombre = leerNoVacio("Ingrese el nombre del experimento: ");
        string descripcion = leerNoVacio("Ingrese su descripción: ");
        try {
            controlador->altaExperimento(nombre, descripcion);
            cout << "Experimento registrado exitosamente";
            break;
        } catch (std::runtime_error& e) {
            cout << "Ocurrió un error: " << e.what() << endl;
        }
    }
    delete controlador;
}

void Menu::definirEventos() {
    IExperimento* controlador = FabricaSistema::getInstancia()->getIExperimento();
    while(true){
        auto experimentos = controlador->listarExperimentos();
        listarExperimentos(experimentos);
        string experimento = leerNoVacio("Ingrese el experimento al que corresponden los eventos: ");
        vector<DTEvento> eventos;
        bool agregarEvento = true;
        while(agregarEvento){
            string nombre = leerNoVacio("Ingrese el evento: ");
            float probabilidad = leerProbabilidad("Ingrese su probabilidad: ");
            eventos.push_back(DTEvento(nombre, probabilidad));
            agregarEvento = leerBooleano("¿Desea agregar otro evento? (1 sí, 0 no): ");
        }
        try {
            controlador->asociarEventos(experimento, eventos);
            break;
        } catch (std::runtime_error& e) {
            cout << "Ocurrió un error: " << e.what() << endl;
        }
    }
    delete controlador;
}

void Menu::simularExperimento() {
    IExperimento* controlador = FabricaSistema::getInstancia()->getIExperimento();
    while(true) {
        auto experimentos = controlador->listarExperimentos();
        listarExperimentos(experimentos);
        string experimento = leerNoVacio("Ingrese el experimento que desea simular: ");
        try {
            DTEvento eventoSimulado = controlador->simularExperimento(experimento);
            cout << "Evento simulado: " << eventoSimulado.getNombre() << endl;
            break;
        } catch (std::runtime_error& e) {
            cout << "Ocurrió un error: " << e.what() << endl;
        }
    }
    delete controlador;
}

void Menu::realizarMultiplesSimulaciones() {
    IExperimento* controlador = FabricaSistema::getInstancia()->getIExperimento();
    while(true) {
        auto experimentos = controlador->listarExperimentos();
        listarExperimentos(experimentos);
        string experimento = leerNoVacio("Ingrese el experimento con el que desea realizar simulaciones: ");
        int cantidad = leerEnteroPositivo("Ingrese la cantidad de simulaciones: ");
        try {
            vector<DTSimulacionExperimento> simulados = controlador->simularExperimento(experimento, cantidad);
            for(auto simulado: simulados){
                cout << simulado << endl;
            }
            break;
        } catch (std::runtime_error& e) {
            cout << "Ocurrió un error: " << e.what() << endl;
        }
    }
    delete controlador;  
}

void Menu::crearVariableAleatoria() {
    IExperimento* controlador = FabricaSistema::getInstancia()->getIExperimento();
    while(true){
        auto experimentos = controlador->listarExperimentos();
        listarExperimentos(experimentos);
        string experimento = leerNoVacio("Ingrese el experimento al que pertenecerá la variable aleatoria: ");
        string variable_id = leerNoVacio("Ingrese el identificador que tendrá dicha variable: ");
        string variable_descripcion = leerNoVacio("Ingrese qué representa " + variable_id + ": ");
        DTDistribucion* distribucion = leerDistribucion("Ingrese la distribución de " + variable_id + ": ");
        try {
            controlador->altaVariableAleatoria(experimento, variable_id, variable_descripcion, distribucion);
            cout << "Variable registrada exitosamente" << endl;
            break;
        } catch (std::runtime_error& e) {
            cout << "Ocurrió un error: " << e.what() << endl;
        }
    }
}

void Menu::simularVariableAleatoria() {
    IExperimento* controlador = FabricaSistema::getInstancia()->getIExperimento();
    while(true){
        auto experimentos = controlador->listarExperimentos();
        listarExperimentos(experimentos);
        string experimento = leerNoVacio("Ingrese el experimento al que pertenece la variable a simular: ");
        auto variablesAleatorias = controlador->listarVariablesAleatorias(experimento);
        listarVariablesAleatorias(variablesAleatorias);
        string variable = leerNoVacio("Ingrese el identificador de dicha variable: ");
        try {
            float valor = controlador->simularVariableAleatoria(experimento, variable);
            cout << "Valor simulado: " << valor << endl;
            break;
        } catch (std::runtime_error& e) {
            cout << "Ocurrió un error: " << e.what() << endl;
        }
    }
}

void Menu::consultarPropiedadNumerica() {
    IExperimento* controlador = FabricaSistema::getInstancia()->getIExperimento();
    while(true){
        auto experimentos = controlador->listarExperimentos();
        listarExperimentos(experimentos);
        string experimento = leerNoVacio("Ingrese el experimento al que pertenece la variable a consultar: ");
        auto variablesAleatorias = controlador->listarVariablesAleatorias(experimento);
        listarVariablesAleatorias(variablesAleatorias);
        string variable = leerNoVacio("Ingrese el identificador de dicha variable: ");
        int opcion = -1;
        try {
            while(opcion != 1 && opcion != 2 && opcion != 3){
                cout << "¿Qué propiedad desea consultar?: " << endl
                    << "1. Esperanza" << endl
                    << "2. Varianza" << endl 
                    << "3. Desvío" << endl;
                    opcion = leerEntero("Opción: ");
                switch(opcion){
                    case 1: {
                        float valor = controlador->consultarPropiedad(experimento, variable, PropiedadNumerica::esperanza);
                        cout << "E(" << variable << ") ≈ " << valor << endl;
                        break;
                    }
                    case 2: {
                        float valor = controlador->consultarPropiedad(experimento, variable, PropiedadNumerica::varianza);
                        cout << "V(" << variable << ") ≈ " << valor << endl;
                        break;
                    }
                    case 3: {
                        float valor = controlador->consultarPropiedad(experimento, variable, PropiedadNumerica::desvio);
                        cout << "σ(" << variable << ") ≈ " << valor << endl;
                        break;
                    }
                    default: {
                        cout << "Opción no válida";
                        break;
                    } 
                }
            }
            break;
        } catch (std::runtime_error& e) {
            cout << "Ocurrió un error: " << e.what() << endl;
        }
    }
    delete controlador;
}

void Menu::evaluarVariableAleatoria() {
    IExperimento* controlador = FabricaSistema::getInstancia()->getIExperimento();
    while(true){
        auto experimentos = controlador->listarExperimentos();
        listarExperimentos(experimentos);
        string experimento = leerNoVacio("Ingrese el experimento al que pertenece la variable a evaluar: ");
        auto variablesAleatorias = controlador->listarVariablesAleatorias(experimento);
        listarVariablesAleatorias(variablesAleatorias);
        string variable = leerNoVacio("Ingrese el identificador de dicha variable: ");
        float x = leerDecimal("Ingrese en qué valor quiere evaluar a " + variable + ": ");
        try {
            float valor = controlador->evaluarVariableAleatoria(experimento, variable, x);
            cout << "P(" << variable << " = " << x << ") ≈ " << valor << endl;
            break;
        } catch (std::runtime_error& e) {
            cout << "Ocurrió un error: " << e.what() << endl;
        }
    }
}

void Menu::evaluarFuncionDistribucionVariableAleatoria() {
    IExperimento* controlador = FabricaSistema::getInstancia()->getIExperimento();
    while(true){
        auto experimentos = controlador->listarExperimentos();
        listarExperimentos(experimentos);
        string experimento = leerNoVacio("Ingrese el experimento al que pertenece la variable a evaluar: ");
        auto variablesAleatorias = controlador->listarVariablesAleatorias(experimento);
        listarVariablesAleatorias(variablesAleatorias);
        string variable = leerNoVacio("Ingrese el identificador de dicha variable: ");
        float x = leerDecimal("Ingrese en qué valor quiere evaluar la distribución acumulada de " + variable + ": ");
        try {
            float valor = controlador->evaluarFuncionDistribucionAcumulada(experimento, variable, x);
            cout << "P(" << variable << " ≤ " << x << ") ≈ " << valor << endl;
            break;
        } catch (std::runtime_error& e) {
            cout << "Ocurrió un error: " << e.what() << endl;
        }
    }
}

void Menu::liberarMemoria() {
    FabricaSistema::liberarMemoria();
    CargaDatos::liberarMemoria();
}