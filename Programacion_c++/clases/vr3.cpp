#include"vr3.h"

vr3::vr3():vrn(3){
    cout<<"Calling vr3 constructor"<<endl;
};

vr3::vr3(double* v):vrn(3){

    for(int i=0;i<3;i++){
        this->v[i]=v[i];
    }

};