#ifndef __vrn_h__
#define __vrn_h__

#include<iostream>
#include<cmath>
using namespace std;

class vrn{
    protected:
        int d; //dimension
        double* v;//puntero crudo que contiene los els
    public:
        // int d; //dimension
        // double* v; //puntero crudo que contiene los els
        vrn(); //constructor por defecto
        vrn(int d); //constructor que crea un vectos de size por defecto
        vrn(const vrn& other);
        vrn(int d, double* v); //constructor copia
        

        ~vrn();//destructor


        void print();
        vrn suma(const vrn& other);
        vrn operator+(const vrn& other);
        vrn& operator=(const vrn& other);
        // ostream& operator<<(ostream& os, const vrn& other); //sobrecarga salida consola
        friend double norm2(vrn& v);
        friend double dot(const vrn& u, const vrn& v);
};
//friend double norm2(vrn& v){
//    double sum=0;
//    for (int i=0;i<v.d;i++){
//        sum+=v.v[i]*v.v[i];
//    }
//    return sum;
//}

#endif