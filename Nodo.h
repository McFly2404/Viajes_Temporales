#ifndef TRABAJO_LENGUAJES_V2_NODO_H
#define TRABAJO_LENGUAJES_V2_NODO_H
#include <string>

struct Nodo {
    int datos;
    std::string cientifico;
    std::string evento;
    Nodo* PtrPasado;
    Nodo* PtrFuturo;
};
#endif //TRABAJO_LENGUAJES_V2_NODO_H
