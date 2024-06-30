#include <iostream> //para cout
#include <stdlib.h> // función para generar numeros aleatorios: rand()
#include <time.h>   // para dar valor a srand(), para el nº aleatorio
#include <fstream>
#include <cmath>
#include<math.h>
#include <limits>
#include <vector>

using namespace std;

struct Punto{
    double x;
    double y;
};

struct Rectangulo
{
    struct Punto up, low;
    double base, altura;
    double area=0,perimetro=0;
};


void hola2(double n, double m){
    n=5;
    m=4;
}

void hola(double &n, double &m){
    n=5;
    m=4;
}

float distancia(Punto &p1, Punto &p2){
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

void area(Rectangulo &r1){
    r1.base=r1.low.x-r1.up.x;
    r1.altura=r1.low.y-r1.up.y;
    r1.area=r1.base*r1.altura;
    r1.perimetro=2*r1.base+2*r1.altura;
    cout<<"area (dentro)= "<<r1.area<<endl;
}

int main(){
    double x=5.5,y=7.4;
    hola2(x,y);
    cout<<"x "<<x<<" y "<<y<<endl;
    hola(x,y);
    cout<<"x "<<x<<" y "<<y<<endl;


    Punto p1, p2;
    p1.x=1;p1.y=3;
    p2.x=20.5;p2.y=30.75;

    cout<<"P1 = "<<p1.x<<" , "<<p1.y<<endl;
    cout<<"P2 = "<<p2.x<<" , "<<p2.y<<endl;  
    cout<<"Distancia= "<<distancia(p1,p2)<<endl;

    Rectangulo r1;
    r1.low=p1; r1.up=p2;
    cout<<" low "<<r1.low.x<<" "<<r1.low.y<<endl;
    cout<<" up "<<r1.up.x<<" "<<r1.up.y<<endl;

    r1.low.x=-1;
    cout<<" P1= "<<p1.x<<", "<<p1.y<<endl;
    cout<<" low "<<r1.low.x<<" "<<r1.low.y<<endl;

    area(r1);
    cout<<" Area (fuera) "<<r1.area<<endl;
}