#include"header.h"
#include"funciones.h"

double compute_norm2(double v[],int n){

    //Calculamos la norma dos de ese array
    double norm2;
    norm2=0;
    for (int i=0;i<n;i++){
        //norm2+=v[i]*v[i];
        norm2+=pow(v[i],2);
    }
    norm2=sqrt(norm2);
    return norm2;
}

//Funcion void: no devuelve nada
void ones(double v[],int n){
//Inicializamos el array todo a 1
    for (int i=0;i<n;i++){
        v[i]=1.;
    }
}

void ones(double A[4][4], int m,int n){
    //Inicializamos el array todo a 1
    for (int i=0;i<m;i++){
        for (int j=0;j<n;j++){
            A[i][j]=1;
        }
    }
}

void print(double v[],int n){
    cout<<"[ ";
        for (int i=0;i<n;i++){
            cout<<v[i];
            if (i<n-1){
                cout<<",";
            }
        }
        cout<<" ]"<<endl;
}

void print(double A[4][4], int m,int n){
    //Inicializamos el array todo a 1
    for (int i=0;i<m;i++){
        for (int j=0;j<n;j++){
            cout<<A[i][j]<<",";
        }
        cout<<endl;
    }
}