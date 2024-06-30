#ifndef FUNCIONES_H_
#define FUNCIONES_H_
using namespace std;
#include <iostream>

class Point {
    public:
        double x;
        double y;
        int index;

        // Constructor
        Point();
        void print();
};

// constructor
inline Point::Point() {
    this->x = 0.;
    this->index = -1;
}

inline void Point::print() {
    cout << "Idx[" << this->index << "]:" << this->x << endl;
}

// Funciones g_0 y g_1
double funcion(double x);
double funcion1(double x);

// Funciones phi_0 y phi_1
double phi0(double x);
double phi1(double x);

// longitud entre dos puntos
float calcularLongitud(Point* p1, Point* p2);

#endif