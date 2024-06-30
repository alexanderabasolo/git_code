#ifndef __triang_h__
#define __triang_h__

#include "nodes.h"

class Triang {
    public:
        Nodes A, B, C;
        Triang(const Nodes& A, const Nodes& B, const Nodes& C); // Constructor con parametros, los nodos
        vector<vector<double>> getcoord() const;
        double areacalculate() const; //funcion para calcular area
};

#endif