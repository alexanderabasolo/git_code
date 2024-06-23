#include <iostream>
#include <stdlib.h> // función para generar numeros aleatorios: rand()
#include <time.h>   // para dar valor a srand(), para el nº aleatorio
#include <fstream>
#include <cmath>
#include <limits>
#include <vector>
#include <cstdlib>

using namespace std;

void modificar(int &a){
    a=5;

    cout<<"dentro "<<a<<endl;
}

void print(float *v,int &n){
    for (int i=0;i<n;i++){
        cout<<v[i]<<"\t";
    }
    cout<<endl;
}

void mod(float *v, int &n){
    for (int i=0;i<n;i++){
        v[i]=3*v[i];
    }
}

//v3 ya viene creado desde fuera
//fuera del metodo ya he hecho un new
//ya he hecho la reserva dinamica de memoria
void sumar(float *v1, float *v2,int &n, float *&v3){

    for (int i=0;i<n;i++){
        v3[i]=v1[i]+v2[i];
    }
    cout<<"dentro"<<endl;
    print(v3,n);
}


void sumar2(float *v1, float *v2,int &n, float *&v3){

    cout<<"v3 (sumar2 - (1))"<<v3<<endl;
    v3=new float[n];
    cout<<"v3 sumar2 - (2)) "<<v3<<endl;
    for (int i=0;i<n;i++){
        v3[i]=v1[i]+v2[i];
    }
    cout<<"dentro"<<endl;
    print(v3,n);
}


void modificar2(float *v, int &dim){
    cout<<" v (antes - mtdo)"<<v<<endl;
    delete [] v;
    v=new float[dim];
    cout<<"despues -mtdo "<<v<<endl;
    for (int i=0;i<dim;i++){
        v[i]=20*i;
    }
}

int main(){
    int b=-2;
    modificar(b);
    cout<<" b (fuera) "<<b<<endl;

    int dim=4;
    float *v1=new float[dim];

    for (int i=0;i<dim;i++){
        v1[i]=-2*i;
    }

    cout<<"v1= "<<v1<<endl;
    print(v1,dim);
    mod(v1,dim);
    print(v1,dim);
    float *v2=new float[dim];
    sumar(v1,v1, dim, v2);
    print(v2,dim);
    float *v3=NULL;
    sumar2(v1, v2, dim, v3);
    cout<<" fuera, dp de sumar2"<<v3<<endl;
    print(v3,dim);

    int dim2=5;
    cout<<"v3 (main - antes) "<<v3<<endl;
    modificar2(v3,dim2);
    cout<<" v3 (main dp) "<<v3<<endl;
    print(v3,dim2);


    delete [] v1,v2;









}