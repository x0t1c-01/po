#include "GestorePrenotazioni.h"

#include <ctime>
#include <random>

GestorePrenotazioni::GestorePrenotazioni() {
    srand(time(0));
}

bool GestorePrenotazioni::esistePrenotazione(int n) {
    for(auto p : prenotazioni) {
        if(p->getNumero() == n)
            return true;
    }
    return false;
}

bool GestorePrenotazioni::aggiungiPrenotazione(int posti, string codice) {
    if(cp.occupaPosti(posti, codice)) {
        int numeroPrenotazione = rand() % 100000;
        while(esistePrenotazione(numeroPrenotazione))
            numeroPrenotazione = rand() % 10000;
        Prenotazione* p = new Prenotazione(numeroPrenotazione, posti, codice);        
        prenotazioni.push_back(p);
        return true;
    }
    else
        return false;        
}

bool GestorePrenotazioni::rimuoviPrenotazione(int numero) {
    for(auto i = prenotazioni.begin(); i != prenotazioni.end(); ++i) {
        if((**i).getNumero() == numero) {
            cp.liberaPosti((**i).getPosti(), (**i).getCodice());
            delete *i;
            prenotazioni.erase(i);
            return true;   
        }            
    }
    return false;    
}

void GestorePrenotazioni::stampaPrenotazioni(string codice) const {
    cout << "Prenotazioni:" << endl;
    for(auto p : prenotazioni) {
        if(p->getCodice() == codice)
            cout << *p << endl;
    }
}

bool ordinamento(Prenotazione* p1, Prenotazione* p2) {
    if(p1->getCodice()[0] == 'a')
        return true;
    if(p2->getCodice()[0] == 'a')
        return false;
    if(p1->getCodice()[0] == 'b')
        return true;
    if(p2->getCodice()[0] == 'b')
        return false;
    if(p1->getCodice()[0] == 'c')
        return true;
    if(p2->getCodice()[0] == 'c')
        return false;
    return p1->getNumero() < p2->getNumero();
}

void GestorePrenotazioni::ordinaPrenotazioni() {
    prenotazioni.sort(ordinamento);
    cout << "Prenotazioni ordinate: " << endl;
    for(auto p : prenotazioni)
        cout << *p << endl;    
}

GestorePrenotazioni::~GestorePrenotazioni() {
    for(auto p : prenotazioni)
        delete p;
}

GestorePrenotazioni& GestorePrenotazioni::operator=(const GestorePrenotazioni& g) {
    if(this != &g) {
        for(auto p : prenotazioni)
            delete p;
        prenotazioni.clear();
        for(auto p : g.prenotazioni) {
            Prenotazione* p1 = new Prenotazione(p->getNumero(), p->getPosti(), p->getCodice());        
            prenotazioni.push_back(p1);
        }
        cp = g.cp;
    }
    return *this;
}

GestorePrenotazioni::GestorePrenotazioni(const GestorePrenotazioni& g) {
    for(auto p : g.prenotazioni) {
        Prenotazione* p1 = new Prenotazione(p->getNumero(), p->getPosti(), p->getCodice());        
        prenotazioni.push_back(p1);
    }
    cp = g.cp;
}