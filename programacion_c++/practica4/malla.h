#ifndef MALLA_H
#define MALLA_H

#include "p1.h"
#include "funciones.h"

class Malla {
public:
    //pueden ser private
    int Nvertices;
    Point *vertices;
    int numElementos;
    ElementoFinitoP1 *elementos;
    double matrizGlobal[6][6];
    double terminoIndep[6];

    //estos son public
    Malla();
    void read_nodes();
    void print_nodes();
    void read_elements();
    void print_elements();
    float calculateLongitudTotal();
    void ensamblar();
    void print_global();
    void ensamblar_TI();
    void print_TI();
    void solveSL();
    void conditions();
};

#endif