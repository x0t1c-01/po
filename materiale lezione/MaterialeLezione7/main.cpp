#include <iostream>
#include <list>
using namespace std;

#include "Prodotto.h"

bool compara(Prodotto* p1, Prodotto* p2) {
    return p1->getPrezzo() < p2->getPrezzo();
}

bool comparaDecr(Prodotto* p1, Prodotto* p2) {
    return p1->getPrezzo() > p2->getPrezzo();
}

int main() {
    list<Prodotto*> l;
    Prodotto* p1 = new Prodotto(1, "descr", 1.0);
    Prodotto* p2 = new Prodotto(2, "descr", 2.0);
    Prodotto* p3 = new Prodotto(3, "descr", 1.5);
    Prodotto* p4 = new Prodotto(4, "descr", 2.5);
    Prodotto* p5 = new Prodotto(5, "descr", 3.5);
    Prodotto* p6 = new Prodotto(6, "descr", 6.0);
    l.push_back(p1);
    l.push_back(p2);
    l.push_back(p3);
    l.push_back(p4);
    l.push_back(p5);
    l.push_back(p6);    
    
    cout << "Stampa della lista" << endl;
    for(auto i = l.begin(); i != l.end(); ++i)
        cout << **i << endl;
    
    cout << "Rimuovo l'elemento con id 2" << endl;
    for(auto i = l.begin(); i != l.end(); ) {
        Prodotto* elem = *i;
        if(elem->getId()==2)
            i = l.erase(i);
        else
            ++i;
    }    
    
    auto it = l.begin();
    cout << "Creo l'iteratore che punta al valore: " << **it << endl;
    advance(it, 3);
    cout << "Mi sposto di 3 posizioni in avanti. Nuovo elemento puntato: " << **it << endl;
    l.insert(it, p6);
    cout << "Ho inserito l'elemento p6 prima dell'elemento puntato. La lista è:" << endl;    
    for(auto i = l.begin(); i != l.end(); ++i)
        cout << **i << endl;
        
    cout << "Ordino la lista in ordine di prezzo crescente" << endl;
    l.sort(compara);
    
    cout << "Ordino la lista in ordine di prezzo decrescente" << endl;
    l.sort(comparaDecr);
    
}