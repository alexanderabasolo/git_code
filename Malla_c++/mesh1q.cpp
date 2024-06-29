//Clase que hereda de Finel
#include"meshq1.h"

mesh1q::mesh1q():Finel(4){

}

void Meshq1::ReadQ1s(){
    int indextemps=0;
    ifstream Ffinels("quad.txt");
    Ffinels>>this->Nfinels;
    //Lectura de fichero de vertices
    this->Lfinels=new Q1[this->Nfinels];
    for(int i=0;i<this->Nfinels;i++){
        this->Lfinels[i]=Finel(4);
        for(int j=0;j<4;j++){
            Ffinels>>indextemps;
            this->Lfinels[i].Vertex[j]=&this->Lvertex[indextemps];
        }

    }
}

