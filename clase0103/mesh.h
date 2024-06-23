#ifndef __mesh_h__
#define __mesh_h__
#include<vector>
#include<list>
#include"point.h"

// El tipo abstracto T va a jugar el papel del tipo de elemento finito
template<typename T>

class Mesh{
    public:
        int Npoints; // numero de puntos
        int Ncells; // numero de elementos finitos
        vector<Point> Lpoints; //almaceno un vector STL de Point
        list<T> Lcells;
        void ReadPoints();
        void PrintPoints();

        void ReadCells();
        void PrintCells();

};

template<typename T>
void Mesh<T>::ReadPoints(){
    //Lectura del fichero
    ifstream Fpoints("nodes.txt");
    Fpoints>>this->Npoints;
    // Dimensionamos el vector de puntos
    this->Lpoints.resize(this->Npoints);
    for(int i=0;i<this->Npoints;i++){
        this->Lvertex[i].Index=i;
        Fpoints>>this->Lpoints[i].x;
        Fpoints>>this->Lpoints[i].y;
    }

    Fpoints.close();
};

template<typename T>
void Mesh<T>::PrintPoints(){
    vector<Points>::iterator it;
    for(it=this->Lpoints[i].begin();it!=this->Lpoints.end();it++){
        it->Print();
    }

    Fpoints.close();
};

template<typename T>
void Mesh<T>::ReadCells(){
    //Lectura del fichero
    ifstream Fpoints("nodes.txt");
    Fpoints>>this->Npoints;
    // Dimensionamos el vector de puntos
    this->Lcells.resize(this->Lcells);
    for(int i=0;i<this->Ncells;i++){
        this->Lvertex[i].Index=i;
        Fpoints>>this->Lcells[i].x;
        Fpoints>>this->Lcells[i].y;
    }
    
    Fpoints.close();
};

template<typename T>
void Mesh<T>::PrintCells(){
    vector<Points>::iterator it;
    for(it=this->Lcells[i].begin();it!=this->Lcells.end();it++){
        it->Print();
    }

    Fpoints.close();
};

#endif