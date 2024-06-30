#include"func_pract1.h"

int main(){
    cout<<"\nBienvenido! Este programa sirve para calcular la serie sum_{k=0}^{infty}frac{3^{k}}{3+k!}.\n";
    cout<<"Se debe introducir el numero de n terminos que se desee sumar.\n";

    double sumaprox = calculate_serie();

    cout <<"\nEl resultado de la serie es: " << sumaprox << endl;

    return 0;

}