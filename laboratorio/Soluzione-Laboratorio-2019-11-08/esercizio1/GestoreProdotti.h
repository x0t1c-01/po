#ifndef GESTORE_PRODOTTI_H
#define GESTORE_PRODOTTI_H

#include <list>
using namespace std;

#include "Prodotto.h"

class GestoreProdotti {

    public:
        GestoreProdotti();
        bool aggiungiProdotto(int id, string descrizione, float prezzo);
        bool modificaProdotto(int id, string descrizione, float prezzo);
        Prodotto* getProdotto(int id) const;
        
        ~GestoreProdotti();
        GestoreProdotti(const GestoreProdotti& g);
        GestoreProdotti& operator=(const GestoreProdotti& g);
    
    private:
        list<Prodotto*> prodotti;
};

#endif