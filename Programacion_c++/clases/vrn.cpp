#include"vrn.h"


//constructor por defecto
vrn::vrn(const vrn& other){
    this->d=other.d;
    this->v=new double[this->d];
    for (int i=0;i<this->d;i++){
        this->v[i]=other.v[i];
    }
}

vrn::vrn(int d){
    cout<<"Calling vrn"<<endl;
    this->d=d;
    this->v=new double[this->d];
    for (int i=0;i<this->d;i++){

    }
}

vrn::vrn(int d, double* v){
    this->d=d;
    this->v=new double[this->d];
    for (int i=0;i<this->d;i++){

    }
}

//destructor de clase
vrn::~vrn(){
    delete[] this->v;
}

void vrn::print(){
    cout<<"[";
    for (int i=0;i<this->d;i++){
        cout<<this->v[i]<<",";
    }
    cout<<"]";
}

vrn vrn::suma(const vrn& other){
    vrn temp(this->d);
    for (int i=0;i<this->d;i++){
        temp.v[i]=this->v[i]+other.v[i];
    }
    return temp;
}

vrn vrn::operator+(const vrn& other){
    vrn temp(this->d);
    for (int i=0;i<this->d;i++){
        temp.v[i]=this->v[i]+other.v[i];
    }
    return temp;
}

vrn& vrn::operator=(const vrn& other){
    for (int i=0;i<this->d;i++){
        this->v[i]=other.v[i];
    }
    return *this;
}

double norm2(vrn& v){
    double sum=0;
    for (int i=0;i<v.d;i++){
        sum+=v.v[i]*v.v[i];
    }
    sum=sqrt(sum);
    return sum;
}
