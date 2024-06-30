//implementacion de la clase
#include "vectores_rn.h"

int vectores_RN::total=0;
//constructor por defectos
vectores_RN::vectores_RN(){
    cout<<"Constructor por defecto"<<endl;
    this->N=0;
    this->vt=NULL;

    this->total++;
}
vectores_RN::vectores_RN(int &dim){
    cout<<"(2) vectores_RN(int &dim)"<<endl;
    this->N=dim;
    this->vt=new double[this->N];
    for (int i=0;i<this->N;i++){
        this->vt[i]=0.;
    }
    vectores_RN::total++;
}

vectores_RN::vectores_RN(const vectores_RN &other){
    cout<<"constructor copia"<<endl;
    this->N=other.N;
    this->vt=new double[this->N];
    for (int i=0;i<this->N;i++){
        this->vt[i]=other.vt[i];
    }
    vectores_RN::total++;
}

vectores_RN::vectores_RN(int &dim, double *v){
    cout<<"constructor via un vt"<<endl;
    this->N=dim;
    this->vt=new double[this->N];
    for (int i=0;i<this->N;i++){
        this->vt[i]=vt[i];
    }
    vectores_RN::total++;
}

vectores_RN::~vectores_RN(){
    cout<<"destructor"<<endl;
    vectores_RN::total--;
}

void vectores_RN::print(){
    for (int i=0;i<this->N;i++){
        cout<<this->vt[i]<<"\t";
    }
    cout<<endl;
}

void vectores_RN::setCoord(int &i,double &val){
    this->vt[i]=val;
}

double vectores_RN::getCoord(int &i){
    return this->vt[i];
}

int vectores_RN::getDim(){
    return this->N;
}

void vectores_RN::sumar(const vectores_RN &v1, const vectores_RN &v2){
    //suponemos que v1 y v2, tienen vectores de la misma dimension
    // en caso de no ser asi, no podríamos sumar
    //habría que lanzar un aviso
    //vamos a permitir que las dimensiones de v1 y v2 no coincidan con las
    //dimensiones de this
    if (this->vt==NULL){
        this->N=v1.N;
        this->vt=new double[this->N];
    }
    if (this->N!=v1.N){
        this->N=v1.N;
        delete[] this->vt;
        this->vt=new double[this->N];
    }
    for (int i=0;i<v2.N;i++){
        this->vt[i]=v1.vt[i]+v2.vt[i];
    }

}

void vectores_RN::prueba(){
    vectores_RN w;
    cout<<vectores_RN::total<<endl;

    for(int i=0;i<5;i++){
        vectores_RN w1;
        cout<<vectores_RN::total<<endl;
    }
    cout<<vectores_RN::total<<endl;
}

int vectores_RN::getTotal(){
    return vectores_RN::total;
}