#include"header.h"

int main(){
    
    int a,b,resultado;
    int operation;

    cout<<"Introduzca los numeros enteros: "<<endl;
    cin>>a>>b;
    cout<<"Operacion a realizar: "<<endl;
    cin>>operation;

    switch(operation){
        case 1:
            resultado=a-b;
            break;
        case 2:
            resultado=a*b;
            break;
        default:
            resultado=a+b;
    }
    cout<<"El resultado es: "<<resultado<<endl;
}