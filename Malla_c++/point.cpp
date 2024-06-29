#include"p1.h"

P1::P1(){
    this->Vertex=new Point*[3];
    for (int i=0; i<3;i++){
        this->Vertex[i]=NULL;
    }
}