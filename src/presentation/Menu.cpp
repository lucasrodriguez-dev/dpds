#include "Menu.h"
#include "FabricaSistema.h"
#include "CargaDatos.h"

void Menu::liberarMemoria() {
    FabricaSistema::liberarMemoria();
    CargaDatos::liberarMemoria();
}