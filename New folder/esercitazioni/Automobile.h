#ifndef AUTOMOBILE_H
#define AUTOMOBILE_H

#include<iostream>
#include<string>

using namespace std;

class Automobile {

private:
    string targa;
    string marca;
    double prezzo;
    int annoprod;

public:
    Automobile(string _targa = "", string _marca ="" , double _prezzo = 0,int _annoprod =1769) : targa(_targa) , marca(_marca) , prezzo(_prezzo) , annoprod(_annoprod){}
    string getTarga()const{return targa;}
    void setTarga(string t){targa =t;}

    string getMarca()const{return marca;}
    void setMarca(string s){marca=s;}

    double getPrezzo()const{return prezzo;}
    void setPrezzo(double d){prezzo=d;}

    int getAnnoprod()const {return annoprod;}
    void setAnnoprod(int z){annoprod=z;}

};
#endif
