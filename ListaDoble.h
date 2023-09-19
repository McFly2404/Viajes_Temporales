#ifndef TRABAJO_LENGUAJES_V2_LISTADOBLE_H
#define TRABAJO_LENGUAJES_V2_LISTADOBLE_H

#include "Nodo.h"

class ListaDoble {
private:
    Nodo* cabeza;
    Nodo* cola;
    bool esPrimo(int numero);
public:
    ListaDoble();
    void agregarNodo(int datos, std::string cientifico);
    void imprimirLista();
    void imprimirEventos();
    void imprimirEventosTipoA();
    void imprimirEventosTipoB();
};


#endif //TRABAJO_LENGUAJES_V2_LISTADOBLE_H
