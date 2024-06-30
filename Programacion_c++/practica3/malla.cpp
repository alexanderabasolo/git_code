#include "malla.h"
#include "nodes.h"
#include "triang.h"

#include <iostream>
#include <fstream>

Malla::Malla(const string& nodes, const string& Conectividades) {

    // Lee los nodos del archivo nodes
    ifstream fileNodos(nodes);
    if(!fileNodos.is_open()){
        cerr<<"Error al abrir el archivo de nodos." <<endl;
        return;
    }

    int numNodos;
    fileNodos>>numNodos;


    //reservamos espacio
    vector<Nodes> nodos;
    nodos.reserve(numNodos);

    // Lee las coordenadas y se almacena en el vector nodos
    for(int  i=0;i<numNodos;++i){
        double x, y;
        fileNodos >> x >> y;

        nodos.push_back(Nodes(x, y));
    }

    fileNodos.close();

    // Lee las conectividades de los nodos desde el archivo triang
    ifstream fileConectividades(Conectividades);
    if (!fileConectividades.is_open()) {
        cerr<<"Error al abrir el archivo de conectividades."<<endl;
        return;
    }

    int numTriangulos;
    fileConectividades>>numTriangulos;

    T.reserve(numTriangulos);

    // Lee los indices de los nodos de cada triangulo y crea objetos Triang con los indices
    for(int i=0;i<numTriangulos;++i){
        int idx1, idx2, idx3;
        fileConectividades>>idx1>>idx2>>idx3;

        T.push_back(Triang(nodos[idx1], nodos[idx2], nodos[idx3]));
    }

    fileConectividades.close();
    nt = T.size(); // se almacena el numero total de triangulos
}

void Malla::areashow() const {
    for (size_t i=0;i<T.size();++i) {
        cout<<"Area del triángulo "<<i + 1<< ": "<<T[i].areacalculate()<<endl; //Imprime el area de cada triangulo
    }
}

Malla::~Malla() {
    //destructor de la clase malla
}