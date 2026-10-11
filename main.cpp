#include <iostream>
#include "Caldero.h"

int main() {
    Caldero calderoExitoso;
    std::string resultadoExitoso = calderoExitoso
        .agregar_ingrediente("Ojo de tritón")
        .agregar_ingrediente("Raíz de mandrágora")
        .calentar(30)
        .calentar(25)
        .revolver(2)
        .revolver(2)
        .embotellar("Poción de Fuerza")
        .getPocima();

    std::cout << resultadoExitoso << "\n\n";

    Caldero calderoSinIngredientes;
    std::cout << calderoSinIngredientes
        .calentar(60)
        .revolver(5)
        .embotellar("Poción Vacía")
        .getPocima() << "\n\n";

    Caldero calderoFrio;
    std::cout << calderoFrio
        .agregar_ingrediente("Pelo de unicornio")
        .calentar(40)
        .revolver(4)
        .embotellar("Poción Tibia")
        .getPocima() << "\n\n";

    Caldero calderoSinRevolver;
    std::cout << calderoSinRevolver
        .agregar_ingrediente("Polvo de hadas")
        .calentar(70)
        .revolver(2)
        .embotellar("Poción Mal Mezclada")
        .getPocima() << "\n\n";

    Caldero calderoPostEmbotellado;
    std::cout << calderoPostEmbotellado
        .agregar_ingrediente("Hoja de menta")
        .calentar(60)
        .revolver(3)
        .embotellar("Poción Refrescante")
        .agregar_ingrediente("Veneno")
        .getPocima() << "\n";

    return 0;
}
