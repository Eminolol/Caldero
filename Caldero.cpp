#include "Caldero.h"

Caldero::Caldero() 
    : cantidad_ingredientes(0), temperatura(0), revoluciones(0), pocima(""), embotellada(false) {}

Caldero& Caldero::agregar_ingrediente(const std::string& ingrediente) {
    if (embotellada) {
        pocima = "Error: No se pueden agregar ingredientes porque la poción ya fue embotellada.";
        return *this;
    }
    if (cantidad_ingredientes < 100) {
        ingredientes[cantidad_ingredientes] = ingrediente;
        cantidad_ingredientes++;
    }
    return *this;
}

Caldero& Caldero::calentar(int grados) {
    if (embotellada) {
        pocima = "Error: No se puede calentar porque la poción ya fue embotellada.";
        return *this;
    }
    if (grados > 0) {
        temperatura += grados;
    }
    return *this;
}

Caldero& Caldero::revolver(int veces) {
    if (embotellada) {
        pocima = "Error: No se puede revolver porque la poción ya fue embotellada.";
        return *this;
    }
    if (veces > 0) {
        revoluciones += veces;
    }
    return *this;
}

Caldero& Caldero::embotellar(const std::string& nombrePocima) {
    if (embotellada) {
        pocima = "Error: La poción ya ha sido embotellada previamente.";
        return *this;
    }

    if (cantidad_ingredientes == 0) {
        pocima = "Error al embotellar: No se puede embotellar si no hay ingredientes.";
        return *this;
    }

    if (temperatura < 50) {
        pocima = "Error al embotellar: La temperatura mínima requerida es 50 °C (temperatura actual: " 
                 + std::to_string(temperatura) + " °C).";
        return *this;
    }

    if (revoluciones < 3) {
        pocima = "Error al embotellar: Se debe haber revolvido al menos 3 veces (revoluciones actuales: " 
                 + std::to_string(revoluciones) + ").";
        return *this;
    }

    embotellada = true;
    pocima = "Poción '" + nombrePocima + "' preparada con éxito.\n"
           + "Ingredientes: [";
    for (int i = 0; i < cantidad_ingredientes; ++i) {
        pocima += ingredientes[i];
        if (i + 1 < cantidad_ingredientes) {
            pocima += ", ";
        }
    }
    pocima += "]\nTemperatura final: " + std::to_string(temperatura) + " °C\n"
           + "Revoluciones: " + std::to_string(revoluciones);

    return *this;
}

std::string Caldero::getPocima() const {
    if (pocima.empty()) {
        return "Error: La poción no ha sido embotellada todavía.";
    }
    return pocima;
}
