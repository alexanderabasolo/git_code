#include"mesh.h"

#include<fstream>

//CONSTRUCTOS MALLA VACIA DE CERO PUNTOS
Mesh::Mesh(){
    this->Nvertex=0;
    this->Lvertex=NULL;

}

void Mesh::ReadPoints(){
    ifstream Fpoints("nodes.txt");
    Fpoints>>this->Nvertex;
    //Lectura de fichero de vertices
    this->Lvertex=new Point[this->Nvertex];
    for(int i=0;i<this->Nvertex;i++){
        this->Lvertex[i].Index=i;
        Fpoints>>this->Lvertex[i].x;
        Fpoints>>this->Lvertex[i].y;

    }
}

void Mesh::PrintPoints(){
    Nvertex;
    for (int i = 0; i < Nvertex; i++){
        
    }
}

void Mesh::ReadFinels(){
    int indextemps=0;
    ifstream Ffinels("quad.txt");
    Ffinels>>this->Nfinels;
    //Lectura de fichero de vertices
    this->Lfinels=new Finel[this->Nfinels];
    for(int i=0;i<this->Nfinels;i++){
        this->Lfinels[i]=Finel(4);
        for(int j=0;j<4;j++){
            Ffinels>>indextemps;
            this->Lfinels[i].Vertex[j]=&this->Lvertex[indextemps];
        }

    }
}

void Mesh::PrintFinels(){
    for(int i=0;i<this->Nfinels;i++){
        this->Lfinels[i].Print();
    }
}

void Mesh::PrintAreas(){
    for(int i=0;i<this->Nfinels;i++){
        this->Lfinels[i].ComputeArea();
    }
}

void Mesh::CalculaAreas(){
    for(int i=0;i<this->Nfinels;i++){
        this->Lfinels[i].ComputeArea();
    }
}