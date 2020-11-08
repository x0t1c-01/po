#include"Vettori.h"
#include<iostream>

using namespace std;

void Vettori::aggiungi(int n){
    v1.push_back(n);
}


void Vettori::aggiungi(char c){
    v2.push_back(c);
}


void Vettori::rimuoviMinori(int n){
    if(v1.empty())
        return;

    vector<int> tmp;
    for(int i=0;i<v1.size();i++){
        if(v1[i]>=n)
            tmp.push_back(v[i]);
    }
    v1.swap(tmp);
}

void Vettori::rimuoviCarattere(char c){
    vector<char> tmp1;
    for(int i=0;i<v2.size();i++){
        if(v2[i]!=c)
            tmp1.push_back(v2[i]);
    }
    v2.swap(tmp1);
}
void genera(){

}

void Vettori::stampa() const {
    cout << "V1:";
    for(int i = 0; i < v1.size(); i++)
        cout << " " << v1[i];
    cout << endl;

    cout << "V2:";
    for(int i = 0; i < v2.size(); i++)
        cout << " " << v2[i];
    cout << endl;

    cout << "V3:";
    for(int i = 0; i < v3.size(); i++)
        cout << " " << v3[i];
    cout << endl;
}
