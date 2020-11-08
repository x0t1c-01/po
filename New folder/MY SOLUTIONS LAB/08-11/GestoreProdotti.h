#idndef GESTOREPRODOTTI_H_
#def GESTOREPRODOTTI_H_

#include"Prodotto.h"
#include<list>

#include<iostream>
using namespace std;

class GestoreProdotti{

public:

    bool aggiungiProdotto(int id, string descrizione, float prezzo);
    bool modificaProdotto(int id, string descrizione, float prezzo);
    Prodotto* getProdotto(int id) const;

private:
    list<prodotto*> prodottii;

};

#endif
