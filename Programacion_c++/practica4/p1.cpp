#include <iostream>
#include <fstream>
using namespace std;
#include "p1.h"
#include "funciones.h"

ElementoFinitoP1::ElementoFinitoP1() {
    this->Nvertices = 0;
    this->Vertices = NULL;
}

ElementoFinitoP1::ElementoFinitoP1(int Nvertex) {
    this->Nvertices = Nvertex;
    this->Vertices = new Point*[this->Nvertices];
}


// matriz local p1
void ElementoFinitoP1::MatrizLocal() {
    double h = calcularLongitud(this->Vertices[0], this->Vertices[1]);
    matrizlocal[0][0] = 1.0 / h + (h/2) * 0.01 * (phi0(-1.)*phi0(-1.)+phi0(1.)*phi0(1.));
    matrizlocal[0][1] = -1.0 / h + (h/2) * 0.01 * (phi0(-1.)*phi1(-1.)+phi0(1.)*phi1(1.));
    matrizlocal[1][0] = -1.0 / h + (h/2) * 0.01 * (phi1(-1.)*phi0(-1.)+phi1(1.)*phi0(1.));
    matrizlocal[1][1] = 1.0 / h + (h/2) * 0.01 * (phi1(-1.)*phi1(-1.)+phi1(1.)*phi1(1.));
}


// termino independiente p1
void ElementoFinitoP1::TerminoIndep() {
    double h = calcularLongitud(this->Vertices[0], this->Vertices[1]);
    terminoindep[0] = h * 0.5 * (funcion(-1.) + funcion(1.));
    terminoindep[1] = h * 0.5 * (funcion1(-1.) + funcion1(1.));
}

//imprime la matriz local p1
void ElementoFinitoP1::printMatrizLocal() {
    cout << "La matriz Local P1: " <<endl;
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            cout << matrizlocal[i][j] << " ";
        }
        cout <<endl;
    }
}


//imprime el termino independiente
void ElementoFinitoP1::printTerminoIndep() {
    cout << "El termino Independiente Local P1: " << endl;
    for (int i = 0; i < 2; ++i) {
        cout << terminoindep[i] << " ";
    }
    cout<<endl;
}

// imprime la clase elementofintioP1
void ElementoFinitoP1::print() {
    cout << "ElementoFinitoP1 - Vertices: ";
    for (int i = 0; i < Nvertices; ++i) {
        cout << Vertices[i]->index << " ";
    }
    cout<<endl;
}