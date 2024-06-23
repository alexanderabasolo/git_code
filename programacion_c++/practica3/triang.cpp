#include "triang.h"
#include <cmath>

Triang::Triang(const Nodes& A, const Nodes& B, const Nodes& C) : A(A), B(B), C(C) {
    // Constructor, inicializa los nodos del triángulo
}

vector<vector<double>> Triang::getcoord() const {
    return {{A.x, A.y}, {B.x, B.y}, {C.x, C.y}}; //vector con las coordenadas de los vertices de cada triangulo
}

double Triang::areacalculate() const {
    return 0.5 * abs((B.x - A.x) * (C.y - A.y) - (C.x - A.x) * (B.y - A.y)); //fórmula área del triangulo en productor vectorial: (b x h)/2
}