#include <iostream>
#include "p1.h"
#include "p2.h"
#include "malla.h"

int main() {
    // Creamos la malla
    Malla malla;

    // Leemos los nodos desde nodos.txt
    malla.read_nodes();

    // Leemos elementos desde elementos.txt
    malla.read_elements();

    // imprimimos nodos
    malla.print_nodes();

    // Imprimimos los elementos
    malla.print_elements();

    // calcula la longitud total de la barra
    malla.calculateLongitudTotal();

    // usamos p1 y p2
    for (int i = 0; i < malla.numElementos; ++i) {
        ElementoFinitoP1 elementoP1(2); // cada elemento tiene 2 puntos
        elementoP1.Vertices = malla.elementos[i].Vertices; // Asignamos los nodos del elemento a p1
        elementoP1.MatrizLocal();
        elementoP1.TerminoIndep();
        elementoP1.printMatrizLocal();
        elementoP1.printTerminoIndep();

        ElementoFinitoP2 elementoP2(3); // cada elemento tiene 3 puntos
        elementoP2.Vertices = malla.elementos[i].Vertices; // Asignamos los nodos del elemento a p2
        elementoP2.MatrizLocal();
        elementoP2.TerminoIndep();
        elementoP2.printMatrizLocal();
        elementoP2.printTerminoIndep();
    }

    // Ensamblamos la matriz global
    malla.ensamblar();

    // Imprimimos la matriz global
    malla.print_global();

    // Ensamblamos el termino independiente
    malla.ensamblar_TI();

    // Imprimimos el termino independiente
    malla.print_TI();

    // Imponemos las condiciones de contorno
    malla.conditions();

    // Resolvemos el sistema
    malla.solveSL();

    return 0;
}
