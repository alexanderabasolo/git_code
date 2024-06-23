#include <iostream>
#include "p1.h"
#include "p2.h"
#include "funciones.h"
using namespace std;

ElementoFinitoP2::ElementoFinitoP2() {
    this->Nvertices = 0;
    this->Vertices = NULL;
}

ElementoFinitoP2::ElementoFinitoP2(int Nvertex) {
    this->Nvertices = Nvertex;
    this->Vertices = new Point*[this->Nvertices];
}

// matriz local p2
void ElementoFinitoP2::MatrizLocal() {
    double h = calcularLongitud(this->Vertices[0], this->Vertices[1]);
    
    matrizlocal[0][0] = 1.0 / h + (h/2)* 0.01*(phi0(-1.)*phi0(-1.)+phi0(1.)*phi0(1.));
    matrizlocal[0][1] = -1.0 / h + (h/2)* 0.01* (phi0(-1.)*phi1(-1.)+phi0(1.)*phi1(1.));
    matrizlocal[0][2] = -1.0 / h + (h/2)* 0.01* (phi0(-1.)*phi1(-1.)+phi0(1.)*phi1(1.));
    
    matrizlocal[1][0] = -1.0 / h + (h/2)* 0.01* (phi1(-1.)*phi0(-1.)+phi1(1.)*phi0(1.));
    matrizlocal[1][1] = 1.0 / h + (h/2)* 0.01*(phi1(-1.)*phi1(-1.)+phi1(1.)*phi1(1.));
    matrizlocal[1][2] = -1.0 / h + (h/2)* 0.01* (phi1(-1.)*phi0(-1.)+phi1(1.)*phi0(1.));
    
    matrizlocal[2][0] = -1.0 / h + (h/2) * 0.01 * (phi1(-1.)*phi0(-1.)+phi1(1.)*phi0(1.));
    matrizlocal[2][1] = -1.0 / h + (h/2)* 0.01 * (phi1(-1.)*phi0(-1.)+phi1(1.)*phi0(1.));
    matrizlocal[2][2] = 1.0 / h + (h/2) * 0.01 * (phi1(-1.)*phi1(-1.)+phi1(1.)*phi1(1.));
}

// termino independiente p2
void ElementoFinitoP2::TerminoIndep() {
    double h = calcularLongitud(this->Vertices[0], this->Vertices[1]);
    
    terminoindep[0] = h * 0.25 * (funcion(-1.) + funcion(1.));
    terminoindep[1] = h * 0.25 * (4 * funcion(0.) + funcion(-1.) + funcion(1.));
    terminoindep[2] = h * 0.25 * (funcion1(-1.) + 4 * funcion1(0.) + funcion1(1.));
}

//imprime la matriz local p2
void ElementoFinitoP2::printMatrizLocal() {
    cout << "Matriz Local P2:" << endl;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cout << matrizlocal[i][j] << " ";
        }
        cout << endl;
    }
}

// imprime la clase elementofintioP2
void ElementoFinitoP2::printTerminoIndep() {
    cout << "Termino Independiente Local P2:" << std::endl;
    for (int i = 0; i < 3; ++i) {
        cout << terminoindep[i] << " ";
    }
    cout << endl;
}