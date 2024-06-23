#include"vrn.h"
#include"vr3.h"

int main(){
    int d=5;
    double *v=new double[5];
    for(int i=0;i<d;i++){
        v[i]=i+1;
    }

    vrn v1(d,v);
    vrn v2(d,v);
    // vrn v3=v1+v2;
    vrn v4(d);
    v4=v1+v2;
    //norm2(v);
    //v4.print();

    vr3 V1;
    V1.print();
    double *vtmp=new double[3];
    for(int i=0;i<d;i++){
        vtmp[i]=1;
    }
    vr3 V2(3,vtmp);
    V2.print();


};