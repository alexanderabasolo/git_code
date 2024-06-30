#ifndef P2_H_
#define P2_H_

#include "funciones.h"

class ElementoFinitoP2 {
    public:
        // Nodos del elemento
        int Nvertices;
        Point **Vertices;
        double matrizlocal[3][3];  // tamaño 3 por 3 que corresponde con P2
        double terminoindep[3];    // dimensión 3 del termino independiente que corresponde con P2
        
        // Constructor
        ElementoFinitoP2();
        ElementoFinitoP2(int Nvertex);
        
        // calcula la matriz local y el término independiente
        void MatrizLocal();
        void TerminoIndep();

        // imprime la matriz local y el termino independiente
        void printMatrizLocal();
        void printTerminoIndep();

        // imprime elementofinitpp2
        void print();
};

#endif