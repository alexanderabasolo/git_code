#include"header.h"
#include"funciones.h"

//Tenemos que declarar las funciones antes de usarlas más abajo, si no no irá

int main(){
    int n=10;
    double v[n];
    //array multidimensional de tamano 4x4
    double A[4][4];

    //inicializo v a 1
    ones(v,n);
    ones(A,4,4);
    print(v,n);
    print(A,4,4);
    cout<<"La norma 2 es: "<<compute_norm2(v,n)<<endl;


}