#include <cmath>
#include "funciones.h"

// Funciones g_0 y g_1
double funcion(double x) {
    return 0.01*30*0.5*(1 - x);
}

double funcion1(double x) {
    return 0.01*30*0.5*(1 + x);
}

// Funciones phi_0 y phi_1
double phi0(double x) {
    return 0.5*(1 - x);
}

double phi1(double x) {
    return 0.5*(1 + x);
}

// longitud entre dos puntos
float calcularLongitud(Point* p1, Point* p2) {
    return abs(p1->x - p2->x);
}