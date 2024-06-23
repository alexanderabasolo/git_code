#include <iostream> //para cout
#include <stdlib.h> // función para generar numeros aleatorios: rand()
#include <time.h>   // para dar valor a srand(), para el nº aleatorio
#include <fstream>
#include <cmath>
#include <limits>
#include <vector>

using namespace std;

int main(){
    float y=10;
    float *py; //una variable de tipo de puntero
    py=NULL;
    cout<<y<<endl;
    cout<<"py= "<<py<<endl;
    cout<<&y<<endl;
    py=&y;
    cout<<"py "<<py<<endl;
    *py=-8;
    cout<<y<<endl;
    cout<<"py= "<<py<<" &y"<<&y<<endl;

    float z=-5.5;
    cout<<"&z= "<<&z<<endl;
    cout<<y<<endl;
    cout<<"py= "<<py<<" &y"<<&y<<endl;

    py=&z;
    cout<<"*py= "<<*py<<endl;
    cout<<"py= "<<py<<" &z"<<&z<<" &y"<<&y<<endl;
    *py=5000;
    cout<<" *py "<<*py<<" z "<<z<<endl;

    int v[]={1,2,3,4};
    int *pv;
    pv=&v[0];
    cout<<v[0]<<" *pv "<<*pv<<endl;
    *pv=-100;
    cout<<v[0]<<" *pv"<<*pv<<endl;
    pv++;//desplazo una posicion
    cout<<"*pv "<<*pv<<" v[1] "<<v[1]<<endl;
    pv+=2;
    cout<<"*pv "<<*pv<<" v[1] "<<v[3]<<endl;
    pv--;
    *pv=400;
    cout<<"*pv "<<*pv<<" v[2] "<<v[2]<<endl;

    pv=&v[0];
    for (int i=0;i<=3;i++){
        cout<<"\n i= "<<i<<" --- "<<*pv;
        pv++;
    }
}