// Martín Caballero y Jose Daniel Castañeda

#include "ListaDoble.h"
#include <iostream>
#include <cstdlib>

int main() {
    srand(time(0));
    ListaDoble lista;

    for (int i = 0; i < 22; ++i) {
        int datos = rand() % 100 + 1;
        std::string cientifico = rand() % 2 == 0 ? "E" : "R";
        lista.agregarNodo(datos, cientifico);
    }

    std::cout << "Los 22 nodos en orden desde la cabeza son:" << std::endl;
    lista.imprimirLista();
    std::cout << "La Lista de Eventos son:" << std::endl;
    lista.imprimirEventos();
    std::cout << "\nLos eventos tipo A son:" << std::endl;
    lista.imprimirEventosTipoA();
    std::cout << "\nLos eventos tipo B son:" << std::endl;
    lista.imprimirEventosTipoB();

    return 0;
}