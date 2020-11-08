#include "Vettori.h"
#include <iostream>
using namespace std;

void Vettori::aggiungi(int n) {
    v1.push_back(n);
}

void Vettori::aggiungi(char c) {
    v2.push_back(c);
}

//Diversi metodi per rimuovere elementi: il primo non mantiene l'ordine
void Vettori::rimuoviMinori(int n) {
    for(int i = 0; i < v1.size(); ) {
        if(v1[i] < n) {
            v1[i] = v1[v1.size()-1];
            v1.pop_back();
        }
        else {
            i++;
        }
    }
}

//Il secondo mantiene l'ordine
void Vettori::rimuoviCarattere(char c) {
    int j = 0;
    for(int i = 0; i < v2.size(); i++) {
        v2[j] = v2[i];
        if(v2[i] != c)
            j++;
    }
    v2.resize(j);
}

void Vettori::genera() {
    char alfabeto[] =
        "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    int length = 26+26+10;

    int n = rand() % 10;
    for(int i = 0; i < n; i++) {
        string s;
        for (int i = 0; i < 3; ++i)
            s += alfabeto[rand() % length];
        v3.push_back(s);
    }
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
