#include"header.h" 
// si quisieramos incluirlo en c++ (no en el local) entonces para llamar seria #include<header.h>
//#include<iostream>
// #include<cmath> // Funciones y variables de tipo matematico
// using namespace std;
// Tambien valdría poner #define PI 3.141592 , esto es una macro


int main(){
    // float pi=4*atan(1); // tambien valdria poner pi=3.141592
    int n=1000; // tamano de la suma parcial
    float suma=0; // Declaro la variable para almacenar la suma parcial y la inicializo
    int i; // contador del bucle
    // Incrementamos el contador con el operador de postincremento
    for (i=1;i<=n;i++){
        suma=suma+1/float(i*i);
    }
    cout<<"Valor de la suma parcial: "<<suma<<endl;
    cout<<"Valor exacto de la suma de la serie: "<<PI*PI/6<<endl;
}