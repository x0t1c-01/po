#include "Supermercato.h"

#include <iostream>
#include <climits>
using namespace std;

void Supermercato::aggiungiProdotto(Prodotto* p) {
    prodotti.push_back(p);
}

void Supermercato::rimuoviProdotto(Prodotto* p) {
    prodotti.remove(p);
}

void Supermercato::stampaInventario() const {
    cout << "Prodotti disponibili: " << endl;
    for(auto it = prodotti.begin(); it != prodotti.end(); ++it) {
        cout << **it << endl;
    }
}

void Supermercato::prodottiEconomici(int n) const {
    list<Prodotto*> prodottiEconomici;
    
    while(prodottiEconomici.size() < n && prodottiEconomici.size() < prodotti.size()) {
        int min = INT_MAX;
        Prodotto* prodottoMin = nullptr;
        for(auto it = prodotti.begin(); it != prodotti.end(); ++it) {
            Prodotto* p = *it;
            if(p->getPrezzo() < min) {
                bool trovato = false;
                for(auto j = prodottiEconomici.begin(); j != prodottiEconomici.end(); ++j) {
                    if(*j == p) {
                        trovato = true;
                        break;
                    }
                }
                if(!trovato) {
                    min = p->getPrezzo();
                    prodottoMin = p;                
                }
            }
        }
        prodottiEconomici.push_back(prodottoMin);
    }
    
    cout << "Prodotti economici:" << endl;
    for(auto it = prodottiEconomici.begin(); it != prodottiEconomici.end(); ++it) {
        cout << **it << endl;
    }
}

void Supermercato::svuota() {
    prodotti.clear();
}