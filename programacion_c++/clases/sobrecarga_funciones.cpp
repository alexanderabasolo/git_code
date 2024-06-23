#include <iostream>
#include <stdlib.h> // función para generar numeros aleatorios: rand()
#include <time.h>   // para dar valor a srand(), para el nº aleatorio
#include <fstream>
#include <cmath>
#include <limits>
#include <vector>
#include <cstdlib>

using namespace std;

int suma(int &a, int &b){
    cout<<"suma (entero)"<<endl;

    return a+b;
}

int suma(float &a, float &b){
    cout<<"suma (float)"<<endl;

    return a+b;
}

void suma(float *v, float *u,int &n, float *&w){
    for (int i=0;i<n;i++){
        w[i]=v[i]+u[i];
    }
}

int main(){
    int a=5, b=7;
    float c=4.5, e=-2.3;
    int dim=3;
    float *v1=new float[dim];
    float *v2=new float[dim];
    float *v3=new float[dim];
    
    cout<<suma(a,b)<<endl;
    cout<<suma(c,e)<<endl;

    for (int i=0;i<dim;i++){
        v1[i]=i*i;
        v2[i]=5*i;
    }
    cout<<"suma de vectores"<<endl;
    suma(v1,v2,dim,v3);
    for(int i=0;i<dim;i++){
        cout<<v3[i]<<"\t";
    }
}