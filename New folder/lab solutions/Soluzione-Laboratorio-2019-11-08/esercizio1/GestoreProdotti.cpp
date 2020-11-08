#include "GestoreProdotti.h"

GestoreProdotti::GestoreProdotti() {
}

bool GestoreProdotti::aggiungiProdotto(int id, string descrizione, float prezzo) {
    for(auto it = prodotti.begin(); it != prodotti.end(); ++it) {
        Prodotto* p = *it;
        if(p->getId() == id) //prodotto già inserito
            return false;
    }
    prodotti.push_back(new Prodotto(id, descrizione, prezzo));
    return true;
}

bool GestoreProdotti::modificaProdotto(int id, string descrizione, float prezzo) {
    for(auto it = prodotti.begin(); it != prodotti.end(); ++it) {
        Prodotto* p = *it;
        if(p->getId() == id) {
            p->setDescrizione(descrizione);
            p->setPrezzo(prezzo);
            return true;
        }
    }
    return false;
}

Prodotto* GestoreProdotti::getProdotto(int id) const {
    for(auto it = prodotti.begin(); it != prodotti.end(); ++it) {
        Prodotto* p = *it;
        if(p->getId() == id) {
            return p;
        }
    }
    return nullptr;
}

GestoreProdotti::~GestoreProdotti() {
    for(auto it = prodotti.begin(); it != prodotti.end(); ++it)
        delete *it;
    prodotti.clear();
}

GestoreProdotti::GestoreProdotti(const GestoreProdotti& g) {
    for(auto it = g.prodotti.begin(); it != g.prodotti.end(); ++it) {
        Prodotto* p = *it;
        aggiungiProdotto(p->getId(), p->getDescrizione(), p->getPrezzo());
    }
}

GestoreProdotti& GestoreProdotti::operator=(const GestoreProdotti& g) {
    if(this != &g) {
        for(auto it = prodotti.begin(); it != prodotti.end(); ++it)
            delete *it;
        prodotti.clear();
        for(auto it = g.prodotti.begin(); it != g.prodotti.end(); ++it) {
            Prodotto* p = *it;
            aggiungiProdotto(p->getId(), p->getDescrizione(), p->getPrezzo());
        }
    }
    return *this;
}