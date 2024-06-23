#include <iostream> //para cout
#include <stdlib.h> // función para generar numeros aleatorios: rand()
#include <time.h>   // para dar valor a srand(), para el nº aleatorio
#include <fstream>
#include <cmath>
#include <limits>
#include <vector>

using namespace std;

int main(){
    int n; //dimension del arrray 1d
    int *p; //una variable de tipo puntero
    cout<<"Numero que quieres introducir"<<endl;
    cin>>n;
    p=new int[n];
    for(int i=0;i<n;i++){
        cin>>p[i];
    }
    cout<<"datos introducidos"<<endl;
    for(int i=0;i<n;i++){
        cout<<p[i]<<"\t";
    }
    cout<<endl;
    delete []p;

}