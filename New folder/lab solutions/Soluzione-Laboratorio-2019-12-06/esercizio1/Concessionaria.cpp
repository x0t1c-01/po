#include "Concessionaria.h"
#include <iostream>
using namespace std;

bool Concessionaria::aggiungi(Veicolo* v) {
    for(auto e : veicoli) {
        if(v->getTarga() == e->getTarga())
            return false;
    }
    veicoli.push_back(v);
    return true;
}

bool Concessionaria::rimuovi(string targa) {
    for(auto it = veicoli.begin(); it != veicoli.end(); ++it)
        if((**it).getTarga() == targa) {
            veicoli.erase(it);
            return true;
        }
    return false;
}

void Concessionaria::stampa() const {
    cout << "Veicoli presenti:" << endl;
    for(auto v : veicoli)
        cout << *v << endl;
}

void Concessionaria::stampaPrezzo(string targa) const {
    for(auto v : veicoli)
        if(v->getTarga() == targa) {
            cout << "Il prezzo del veicolo con targa " << targa << " è: " << v->getPrezzo() << endl;
            return;
        }
    cout << "Veicolo non trovato!" << endl;
}