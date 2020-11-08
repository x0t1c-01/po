#ifndef VEICOLO_H
#define VEICOLO_H

#include<string>
#include<iostream>

using namespace std;

enum Tipo {Automobile = 0, Moto};

class Veicolo(){

private:
    string targa;
    string casaProd;
    double prezzo;
    string nome;
    Tipo tipo;

public:
    Veicolo(string _targa = "", string _casaProd ="" , double _prezzo = 0,string nome ="",Tipo _tipo = 0) : targa(_targa) , casaProd(_casaProd) , prezzo(_prezzo) , nome(_nome),tipo(_tipo){}

    string getTarga()const{return targa;}
    void setTarga(string t){targa =t;}

    string getCasaProd()const{return casaProd;}
    void setCasaProd(string s){casaProd=s;}

    double getPrezzo()const{return prezzo;}
    void setPrezzo(double d){prezzo=d;}

    string getNome()const {return nome;}
    void setNome(string z){nome=z;}

    Tipo getTipo() const { return tipo; }
    void setTipo(Tipo v) { tipo = v; }

};
#endif
