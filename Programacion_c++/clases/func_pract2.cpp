#include "func_pract2.h"

void read(const char *nombreArchivo, int **&matriz, int &filas, int &columnas) {
    ifstream archivo(nombreArchivo);
    if (archivo.is_open()) {
        // Lee las dimensiones de la matriz desde el archivo
        archivo >> filas >> columnas; 
        // Reserva de memoria para las filas
        matriz = new int *[filas];      
        for (int i = 0; i < filas; ++i) {
            // Reserva memoria para las columnas
            matriz[i] = new int[columnas];  
            for (int j = 0; j < columnas; ++j) {
                // Lee los elementos de la matriz desde el archivo
                archivo >> matriz[i][j];  
            }
        }
        archivo.close();
    } else {
        cerr << "No se pudo abrir el archivo." << endl;
    }
}

void print(const int **matriz, int filas, int columnas) {
    for (int i = 0; i < filas; ++i) { 
        //recorre las filas
        for (int j = 0; j < columnas; ++j) { 
            //recorre las columnas
            cout << matriz[i][j] << " "; //imprime la posicion
        }
        cout << endl;
    }
}

void add(const int **matriz1, const int **matriz2, int **resultado, int filas, int columnas) {
    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            //suma las posiciones iguales
            resultado[i][j] = matriz1[i][j] + matriz2[i][j]; 
        }
    }
}

void restar(const int **matriz1, const int **matriz2, int **resultado, int filas, int columnas) {
    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            //resta las posiciones iguales
            resultado[i][j] = matriz1[i][j] - matriz2[i][j]; 
        }
    }
}

void mu(const int **matriz1, const int **matriz2, int **resultado, int filas1, int columnas1, int filas2, int columnas2) {
    // Iterar sobre las filas de la primera matriz
    for (int i = 0; i < filas1; ++i) {
        for (int j = 0; j < columnas2; ++j) {
            // inicializa un acumulador
            resultado[i][j] = 0;
            // Itera las columnas
            for (int k = 0; k < columnas1; ++k) {
                //multiplica las posiciones de las matrices
                resultado[i][j] += matriz1[i][k] * matriz2[k][j];
            }
        }
    }
}