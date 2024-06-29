#include<iostream>
#include<vector>
#include<list>
using namespace std;

// funcion que calcula la suma de las componentes

//template<typename T>
//T suma(T v[5]){
//    T suma=0;
//    for(int i=0;i<5;i++){
//        suma+=v[i];
//    }
//    return suma;
//}

int main(){
    list<double> L; //vector STL de double

    // anade por el final del contenedor
    for (int i=0;i<10;i++){
        L.push_back(i+1);
    }

    cout<<"Size de la lista: "<<L.size()<<endl;

    //declaro un iterador para recorrer la clase lista
    list<double>::iterator it;

    for(it=L.begin();it!=L.end();it++){
        cout<<*it<<","; //el iterador es como un iterador de punteros, por eso aqui lo desreferenciamos con *it
        // se debe desreferenciar para que compile, si no ni siquiera compilara
    }

    
}