#ifndef SUPERMERCATO_H_
#def SUPERMERCATO_H_



#include"Prodotto.h"
#include<iostream>
#include<list>

using namespace std;

class Supermercato(){

public:
    void aggiungiProdotto(Prodotto*);
    void rimuoviProdotto(Prodotto*);
    void stampaInventario() const;
    void prodottiEconomici(int n) const;
    void svuota();

private:
    list<Prodotto*> prodotti;

};





#endif
