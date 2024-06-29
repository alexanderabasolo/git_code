#include"Q1.h"

Q1::Q1():Finel(4){

}

void Q1::ComputeArea(){
    double base =this->Vertex[1].x - this->Vertex[0]->x;
    double height =this->Vertex[2].y - this->Vertex[1]->y;
    this->Area=base*height;
}