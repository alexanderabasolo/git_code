#include <iostream> //para cout
#include <stdlib.h> // función para generar numeros aleatorios: rand()
#include <time.h>   // para dar valor a srand(), para el nº aleatorio
#include <fstream>
#include <cmath>
#include <limits>
#include <vector>

using namespace std;

int main(){
    int nfila,ncol;
    double **A; //puntero de puntero
    nfila=4;
    ncol=3;
    A=new double*[nfila];
    for(int i=0;i<nfila;i++){
       A[i]=new double[ncol]; //hacemos la reserva para la fila
    }
    for(int i=0;i<nfila;i++){//me muevo en filas
        for (int j=0;j<ncol;j++){
            A[i][j]=i+j;
        }
       A[i]=new double[ncol]; //hacemos la reserva para la fila
    }
    //imprimir matriz
    cout<<"Imprimo matriz"<<endl;
    for(int i=0;i<nfila;i++){//me muevo en filas
        for (int j=0;j<ncol;j++){
            cout<<A[i][j]<<"\t";
        }
       cout<<endl;
    }
    //borrar memoria
    for (int i=0;i<nfila;i++){
        delete [] A[i];//borramos los punteros interiores

    }
    delete []A;//borramos el puntero de punteros
}