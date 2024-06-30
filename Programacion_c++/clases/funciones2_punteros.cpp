#include <iostream>
#include <stdlib.h> // función para generar numeros aleatorios: rand()
#include <time.h>   // para dar valor a srand(), para el nº aleatorio
#include <fstream>
#include <cmath>
#include <limits>
#include <vector>
#include <cstdlib>

using namespace std;

void print(float **M, int &m, int&n){
    for (int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cout<<M[i][j]<<"\t";
        }
        cout<<endl;
    }
}


void inicializar(float **&M, int&m, int &n, float &val){
    M=new float*[m];
    for (int i=0;i<m;i++){
        M[i]=new float[n];
    }
    for (int i=0; i<m;i++){
        for (int j=0;j<n;j++){
            M[i][j]=val*(i+j);
        }
    }

}

void suma(float **A, float **B, int&m, int&n, float **&C){

    C=new float*[m];
    for (int i=0;i<m;i++){
        C[i]=new float[n];
    }
    for (int i=0; i<m;i++){
        for (int j=0;j<n;j++){
            C[i][j]=A[i][j]+ B[i][j];
        }
    }
    //print(C,m,n);
}

void sumar2(float **A, float **B, int&m, int&n, float **&C){

    float **C;
    reserva(C,m,n);
    for (int i=0; i<m;i++){
        for (int j=0;j<n;j++){
            C[i][j]=A[i][j]+ B[i][j];
        }
    }
    print(C,m,n);

    for (int=0;i<m;i++){
        delete[] C[i];
    }

    delete[] C;
}

int main(){
    int m=3,n=2;
    float **M1, **M2, **M3;
    float aux=5.1;
    inicializar(M1,m,n,aux);
    print(M1,m,n);

    aux=-1.2
    inicializar(M2,m,n,aux);
    cout<<"M2"<<endl;
    print(M2,m,n);

    float **M3;

    suma(M1,M2,m,n,M3);

    cout<<"Suma= "<<endl;
    print(M3,m,n);
    cout<<" Sumar 2 - no devuelve nada"<<endl;
    sumar2(M1,M2,m,n);

    for (int j=0;j<n;j++){
        delete[] M1[i], M2[i];
    }

    delete[] M1;
}