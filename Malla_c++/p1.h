#ifndef __p1_h__
#define __p1_h__


#include"header.h"
#include"point.h"



class P1{
    public:
        Point** Vertex; //lista de direcciones a puntos
        P1();
        void Print();
}

#endif