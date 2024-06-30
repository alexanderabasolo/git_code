//malla.cpp

#include <iostream>
#include <vector>
#include <fstream>
#include "p1.h"
#include "malla.h"
#include "funciones.h"
#include <cmath>

using namespace std;

// Constructor de Malla
Malla::Malla() {
    this->Nvertices = 0;
    this->vertices = NULL;
    this->numElementos = 0;
    this->elementos = NULL;
}

// Imponemos las condiciones de contorno
void Malla::conditions() {
    // Condicion de contorno en el extremo izquierdo de la barra
    matrizGlobal[0][0] = 1;
    for(int j = 1; j < this->Nvertices; j++) {
        matrizGlobal[0][j] = 0.;
    }
    terminoIndep[0] = 40;

    // La condicion de contorno en el extremo derecho de la barra
    matrizGlobal[this->Nvertices - 1][this->Nvertices - 1] = 1;
    for(int j = 0; j < (this->Nvertices - 1); j++) {
        matrizGlobal[this->Nvertices - 1][j] = 0.;
    }
    terminoIndep[this->Nvertices - 1] = 150;
}

// Esta funcion lee los nodos de un archivo.txt
void Malla::read_nodes() {
    ifstream Fpoints("nodos.txt");
    Fpoints >> this->Nvertices;
    this->vertices = new Point[this->Nvertices];
    for(int i = 0; i < this->Nvertices; ++i) {
        this->vertices[i].index = i;
        Fpoints >> this->vertices[i].x;
    }
    Fpoints.close();
}

// Imprime los nodos de la malla
void Malla::print_nodes() {
    cout << "Mallado:" << endl << "Número de vértices: " << this->Nvertices << endl;
    for(int i = 0; i < this->Nvertices; ++i) this->vertices[i].print();
}

// Lee los elementos desde un archivo.txt (los subintervalos)
void Malla::read_elements() {
    int idxtmp;
    ifstream Ffinel("elementos.txt");
    Ffinel >> this->numElementos;
    this->elementos = new ElementoFinitoP1[this->numElementos];
    for(int i = 0; i < this->numElementos; ++i) {
        this->elementos[i] = ElementoFinitoP1(2);
        for(int j = 0; j < 2; ++j) {
            Ffinel >> idxtmp;
            this->elementos[i].Vertices[j] = &this->vertices[idxtmp];
        }
    }
    Ffinel.close();
}

// Imprime los elementos de la malla
void Malla::print_elements() {
    cout << "Mallado:" << endl << "Número de elementos finitos: " << this->numElementos << endl;
    for(int i = 0; i < this->numElementos; ++i) {
        cout << "Elemento finito: " << i+1 << endl;
        this->elementos[i].print();
        this->elementos[i].printMatrizLocal();
        this->elementos[i].printTerminoIndep();
    }
}

// Calcula la longitud total de la malla
float Malla::calculateLongitudTotal() {
    cout << "Mallado: calculando longitud de elementos finitos subyacentes." << endl;
    float sum = 0;
    for(int i = 0; i < this->numElementos; ++i) sum += calcularLongitud(this->elementos[i].Vertices[0], this->elementos[i].Vertices[1]);
    cout << "Longitud total de la barra: " << sum << endl;
    return sum;
}

// Ensamblar la matriz global, combina la matriz local de cada nodo y elemento
void Malla::ensamblar() {
    for (int i = 0; i < this->Nvertices; i++) {
        for (int j = 0; j < this->Nvertices; j++) {
            matrizGlobal[i][j] = 0.0;
        }
    }

    for (int i = 0; i < this->numElementos; ++i) {
        this->elementos[i].MatrizLocal();

        int j = this->elementos[i].Vertices[0]->index;
        int k = this->elementos[i].Vertices[1]->index;

        matrizGlobal[j][j] += this->elementos[i].matrizlocal[0][0];
        matrizGlobal[j][k] += this->elementos[i].matrizlocal[0][1];
        matrizGlobal[k][j] += this->elementos[i].matrizlocal[1][0];
        matrizGlobal[k][k] += this->elementos[i].matrizlocal[1][1];
    }
}

// Imprime la matriz global
void Malla::print_global() {
    cout << "Global Matrix:" << endl;
    for (int i = 0; i < Nvertices; ++i) {
        for (int j = 0; j < Nvertices; ++j) {
            cout << matrizGlobal[i][j] << " ";
        }
        cout << endl;
    }
}

// Ensambla el término independiente
void Malla::ensamblar_TI() {
    for (int i = 0; i < this->Nvertices; i++) {
        terminoIndep[i] = 0.0;
    }

    for (int i = 0; i < this->numElementos; ++i) {
        this->elementos[i].TerminoIndep();

        int j = this->elementos[i].Vertices[0]->index;
        int k = this->elementos[i].Vertices[1]->index;

        terminoIndep[j] += this->elementos[i].terminoindep[0];
        terminoIndep[k] += this->elementos[i].terminoindep[1];
    }
}

// Imprime el término independiente
void Malla::print_TI() {
    cout << "Termino Independiente Global:" << endl;
    for (int i = 0; i < Nvertices; ++i) {
        cout << terminoIndep[i] << " ";
    }
    cout << endl;
}

// Resolucion del sistema con Jacobi
void Malla::solveSL() {
    // Crear un vector para almacenar las soluciones actuales y actualizadas
    vector<double> u(this->Nvertices, 0.0);
    vector<double> u_new(this->Nvertices, 0.0);

    // Tolerancia de convergencia y numero maximo de iteraciones
    double tol = 1e-14;
    int maxIter = 10000;
    int iter = 0;

    // Jacobi hasta la convergencia o el número máximo de iteraciones
    while (iter < maxIter) {
        // Renueva solución en cada nodo usando el método de Jacobi
        for (int i = 0; i < this->Nvertices; ++i) {
            double sum = 0.0;
            for (int j = 0; j < this->Nvertices; ++j) {
                if (j != i) {
                    sum += matrizGlobal[i][j] * u[j];
                }
            }
            u_new[i] = (terminoIndep[i] - sum) / matrizGlobal[i][i];
        }

        // Convergencia
        double err = 0.0;
        for (int i = 0; i < this->Nvertices; ++i) {
            err += (u_new[i] - u[i]) * (u_new[i] - u[i]);
        }
        err = sqrt(err);
        if (err < tol) {
            break;
        }

        // Actualizar el vector de solución
        u = u_new;
        iter++;
    }

    // Imprimir el vector de solución
    cout << "Solucion: ";
    for (int i = 0; i < this->Nvertices; ++i) {
        cout << u[i] << " ";
    }
    cout << endl;
}