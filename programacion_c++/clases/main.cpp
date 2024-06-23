#include <iostream>
#include <stdlib.h> // función para generar numeros aleatorios: rand()
#include <time.h>   // para dar valor a srand(), para el nº aleatorio
#include <fstream>
#include <cmath>
#include <limits>
#include <vector>
#include <cstdlib>

using namespace std;

#include "vectores_rn.h"

int main(){
    //cout<<"hola";
    vectores_RN v1; //creo un objeto de mi clase
    //cout<<v1.N<<endl;
    //cout<<v1.vt<<endl;
    int dim=4;
    vectores_RN v2=vectores_RN(dim);//FORMA CORRECTAR DE LLAMAR AL CONSTRUCTOR, SOLO SE PUEDE LLAMAR UNA VEZ AL CONSTRUCTOR
    vectores_RN v3=vectores_RN(dim);
    vectores_RN v4=vectores_RN(v3);
    double *v=new double [4];
    for (int i=0;i<dim;i++) v[i]=3*i;
    vectores_RN v5=vectores_RN(dim, v);
    void print();
    cout<<"v5"<<endl;
    v5.print();
    cout<<"v2"<<endl;
    v2.print();
    int i=0;
    double val=4;
    v3.setCoord(i, val);
    cout<<"v3"<<endl;
    v3.print();
    cout<<"v5"<<endl;
    for (int i=0;i<v5.getDim();i++){
        cout<<v5.getCoord(i)<<"\t";
    }
    cout<<endl;
    v2.sumar(v3,v5);
    cout<<"v2"<<endl;
    v2.print();
    v1.sumar(v2,v5);
    v1.print();
    dim=1;
    vectores_RN v6=vectores_RN(dim);
    v6.sumar(v2,v5);
    v6.print();

    cout<<v1.getTotal()<<" "<< v5.getTotal()<<" "<< vectores_RN::getTotal()<<endl;
    v1.prueba();
    cout<<v1.getTotal()<<" "<< v5.getTotal()<<" "<< vectores_RN::getTotal()<<endl;
}