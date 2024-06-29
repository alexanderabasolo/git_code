#include"finel.h"

Finel::Finel(){
    this->Nvertex=0;
    this->Vertex=NULL;
}

Finel::Finel(int Nvertex){
    this->Nvertex=Nvertex;
    this->Vertex=new Point*[Nvertex];
}

void Finel::Print(){
    for(int i=0;this->Nvertex;i++){
        this->Vertex[i]->Print();
    }
    cout<<endl;
}

void Finel::ComputeArea(){
    this->Area=0.;
}