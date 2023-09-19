#include "ListaDoble.h"
#include <iostream>
#include <cstdlib>
ListaDoble::ListaDoble() : cabeza(nullptr), cola(nullptr) {}

bool ListaDoble::esPrimo(int numero) {
    if (numero <= 1) return false;
    if (numero == 2) return true;
    if (numero % 2 == 0) return false;
    for (int i = 3; i * i <= numero; i += 2) {
        if (numero % i == 0) return false;
    }
    return true;
}

void ListaDoble::agregarNodo(int datos,std::string cientifico) {
    Nodo* nuevoNodo = new Nodo;
    nuevoNodo->datos = datos;

    static int contadorPrimos = 0;

    if (esPrimo(datos)) {
        contadorPrimos++;
        switch (contadorPrimos % 3) {
            case 1:
                nuevoNodo->evento = "A";
                nuevoNodo->cientifico = "E";
                break;
            case 2:
                nuevoNodo->evento = "B";
                nuevoNodo->cientifico = rand() % 2 == 0 ? "E" : "R";
                break;
            case 0:
                nuevoNodo->evento = "C-primo";
                nuevoNodo->cientifico = rand() % 2 == 0 ? "E" : "R";
                break;
        }
    } else if (cola != nullptr && cola->evento == "B") {
        contadorPrimos++;
        if (contadorPrimos % 3 == 0) {
            nuevoNodo->evento = "C-coprimo";
            nuevoNodo->cientifico = rand() % 2 == 0 ? "E" : "R";
        }
    } else {
        nuevoNodo->evento = "Normal";
        nuevoNodo->cientifico = rand() % 2 == 0 ? "E" : "R";

    }

    nuevoNodo->PtrPasado = cola;
    nuevoNodo->PtrFuturo = nullptr;

    if (cabeza == nullptr) {
        cabeza = nuevoNodo;
    } else {
        cola->PtrFuturo = nuevoNodo;
    }
    cola = nuevoNodo;
}


void ListaDoble::imprimirLista() {
    Nodo* temp = cabeza;
    while (temp != nullptr) {
        std::cout << temp->datos << "|" << temp->cientifico << "|" << temp->evento << std::endl;
        temp = temp->PtrFuturo;
    }
}
void ListaDoble::imprimirEventos() {
    Nodo* temp = cabeza;
    while (temp != nullptr) {
        if (temp->evento == "A" || temp->evento == "B" || temp->evento == "C-primo" || temp->evento == "C-coprimo") {
            std::cout << temp->datos << " | " << temp->cientifico << " | " << temp->evento;
            if (temp->evento == "C-primo") {
                std::cout << " (El cientifico 2 pudo entregar informacion)";
            } else if (temp->evento == "C-coprimo") {
                std::cout << " (El cientifico 2 solo pudo observar)";
            }
            std::cout << std::endl;
        }
        temp = temp->PtrFuturo;
    }
}


void ListaDoble::imprimirEventosTipoA() {
    Nodo* temp = cabeza;
    int contador = 0;
    while (temp != nullptr) {
        if (temp->evento == "A") {
            std::cout << temp->datos << "|" << temp->cientifico << "|" << temp->evento << std::endl;
            contador++;
        }
        temp = temp->PtrFuturo;
    }
    std::cout << "Cantidad de eventos tipo A: " << contador << std::endl;
}

void ListaDoble::imprimirEventosTipoB() {
    Nodo* temp = cabeza;
    int contador = 0;
    while (temp != nullptr) {
        if (temp->evento == "B") {
            std::cout << temp->datos << "|" << temp->cientifico << "|" << temp->evento << std::endl;
            contador++;
        }
        temp = temp->PtrFuturo;
    }
    std::cout << "Cantidad de eventos tipo B: " << contador << std::endl;
}


