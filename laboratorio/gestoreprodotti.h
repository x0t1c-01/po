#ifndef GESTOREPRODOTTI_H
#define GESTOREPRODOTTI_H

class GestoreProdotti{
public:

    bool aggiungiProdotto(int id, string descrizione, float prezzo);
    bool modificaProdotto(int id, string descrizione, float prezzo);
    Prodotto* getProdotto(int id) const;

private:
    list<Prodotto*> prod;
};
bool GestoreProdotti::aggiungiProdotto(int id, string descrizione, float prezzo){


    prod.push_back(new Prodotto(id,descrizione,prezzo));
}


#endif
