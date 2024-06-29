#include"mesh.h"
#include"p1.h"
#include"header.h"

int main(){
    //instancio un objeto de tipo "malla de P1s"
    Mesh<P1> M;
    M.ReadPoints();
    M.PrintPoints();

}