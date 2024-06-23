#include"header.h"
#include"point.h"

#ifndef __finel_h__
#define __finel_h__

class Finel{
    public:
        int Nvertex;
        int Area;
        Point** Vertex; // Puntero a direcciones de puntos
        Finel();
        Finel(int Nvertex);
        void Print();
        virtual void ComputeArea()=0; //funcion virtual PURA
};

#endif