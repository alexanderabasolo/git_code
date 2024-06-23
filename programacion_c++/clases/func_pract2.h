#include <iostream>
#include <stdlib.h> // función para generar numeros aleatorios: rand()
#include <time.h>   // para dar valor a srand(), para el nº aleatorio
#include <fstream>
#include <cmath>
#include <limits>
#include <vector>
#include <cstdlib>

using namespace std;

#ifndef FUNC_PRACT2_H //comprueba que no este definido ya
#define FUNC_PRACT2_H //se define

//definicion de prototipos
void read(const char *nombreArchivo, int **&matriz, int &filas, int &columnas);
void print(const int **matriz, int filas, int columnas);
void add(const int **matriz1, const int **matriz2, int **resultado, int filas, int columnas);
void restar(const int **matriz1, const int **matriz2, int **resultado, int filas, int columnas);
void mu(const int **matriz1, const int **matriz2, int **resultado, int filas1, int columnas1, int filas2, int columnas2);
#endif