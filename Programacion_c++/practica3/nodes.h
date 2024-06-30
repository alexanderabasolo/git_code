#ifndef __nodes_h__
#define __nodes_h__

#include<iostream>
#include<cmath>
#include <vector>
using namespace std;

class Nodes{
    public:
        double x, y;
        Nodes(); //constructor por defecto
        Nodes(double x, double y): x(x), y(y) {}; //constructor con coordenadas

};
#endif