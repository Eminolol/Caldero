#ifndef CALDERO_H
#define CALDERO_H

#include <string>

class Caldero {
private:
    std::string ingredientes[100];
    int cantidad_ingredientes;
    int temperatura;
    int revoluciones;
    std::string pocima;
    bool embotellada;

public:
    Caldero();

    Caldero& agregar_ingrediente(const std::string& ingrediente);
    Caldero& calentar(int grados);
    Caldero& revolver(int veces);
    Caldero& embotellar(const std::string& nombrePocima);

    std::string getPocima() const;
};

#endif
