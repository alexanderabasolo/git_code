#ifndef __vr3_h__
#define __vr3_h__

#include"vrn.h"
using namespace std;

class vr3:public vrn{
    public:
        static int vr3counter;
        vr3();
        vr3(double* v);

};

#endif