#ifndef __malla_h__
#define __malla_h__

#include "nodes.h"
#include "triang.h"
#include <string>
#include <vector>



class Malla {
    private:
        int nt;
        vector<Triang> T;
        
    public:
        Malla(const string& filenodes, const string& Conectividades);
        ~Malla();
        void areashow() const;
};

#endif