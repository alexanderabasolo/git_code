/*
Pedimos dos numeros enteros por pantalla y calcula su suma y su producto y los imprime por pantalla
*/
#include<iostream>
using namespace std;


int main(){
    // Declaramos 4 variables de tipo entero
    int a,b,s,p;
    // Pedir dos enteros por pantalla
    cout<<"Introduzca dos numeros enteros:"<<endl;
    cin>>a>>b;
    cout<<"Los numeros introducidos son: "<<a<<" , "<<b<<endl;

    // Hacemos la suma y producto
    s=a+b;
    p=a*b;
    cout<<"La suma es: "<<s<<endl;
    cout<<"El producto es: "<<p<<endl;
}