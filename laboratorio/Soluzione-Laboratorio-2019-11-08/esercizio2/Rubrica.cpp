#include "Rubrica.h"

#include <iostream>
using namespace std;

void Rubrica::aggiungiNumero(string nome, string numero) {
    nomi.push_back(nome);
    numeri.push_back(numero);
}

string Rubrica::getNumero (string nome) const {
    for(int i = 0; i < nomi.size(); i++) {
        if(nomi[i]==nome)
            return numeri[i];
    }
    return "";
}

void Rubrica::modificaNumero (string nome, string numero) {
    for(int i = 0; i < nomi.size(); i++) {
        if(nomi[i]==nome)
            numeri[i]=numero;
    }
}

void Rubrica::stampa() const {
    cout << "Rubrica:" << endl;
    for(int i = 0; i < nomi.size(); i++) {
        cout << nomi[i] << ": " << numeri[i] << endl;
    }
}