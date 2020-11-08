#ifndef SUPERMERCATO_H
#define SUPERMERCATO_H

#include <list>
using namespace std;
#include "Prodotto.h"

class Supermercato {

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