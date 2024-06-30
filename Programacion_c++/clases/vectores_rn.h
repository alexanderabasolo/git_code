//descripcion de la clase

#include <iostream>
#include <stdlib.h> // función para generar numeros aleatorios: rand()
using namespace std;

#ifndef VECTORES_RN_H
#define VECTORES_RN_H



class vectores_RN{

    private: //no son accesibles desde fuera. Atributos o metodos privados
        int N;
        double *vt;
        vectores_RN(); //constructor por defectos, debe contener el mismo nombre de la clase, sirve para inicializar los atributos del objeto y realizar cualquier configuracion inicial necesaria
        static int total;
    public: //declaramos atributos y metodos publicos
        //static int total;
        vectores_RN();
        vectores_RN(int &dim); //constructor
        vectores_RN(const vectores_RN &other);
        vectores_RN(int &dim, double *v);
        ~vectores_RN();//destructor-- solo puede haber un destructor
        void print();
        void setCoord(int &i,double &val);
        double getCoord(int &i);
        int getDim();
        void sumar(const vectores_RN &v1, const vectores_RN &v2);
        void prueba();
        static int getTotal(); //solo va aqui el static, es decir, en su definicion
};
#endif