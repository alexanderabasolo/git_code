#include"func_pract1.h"
#include <iostream>

int main()
{
    // Función para crear un vector aleatorio y que se guarde en un fichero
    crear_vectores();

    // Función para realizar el cálculo
    std::cout << "El resultado del producto escalar es: " << calculo_prod_esca() << std::endl;

    return 0;
}