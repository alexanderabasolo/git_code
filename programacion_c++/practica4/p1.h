#ifndef P1_H_
#define P1_H_
#include "funciones.h"

class ElementoFinitoP1 {
    public:
        // Nodos del elemento
        int Nvertices;
        Point **Vertices;
        double matrizlocal[2][2];
        double terminoindep[2];
        
        // Constructor de P1
        ElementoFinitoP1();
        ElementoFinitoP1(int Nvertex);
        
        // Calcula la matriz local y el término independiente
        void MatrizLocal();
        void TerminoIndep();

        // imprime la matriz local y el termino independiente
        void printMatrizLocal();
        void printTerminoIndep();

        // imprimir
        void print();
};

#endif  // P1_H_
