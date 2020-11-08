#ifndef GESTORE_LEZIONI_H
#define GESTORE_LEZIONI_H

#include "Lezione.h"
#include <list>
using namespace std;

class GestoreLezioni {
    
    public:        
        //Metodi da implementare (File GestoreLezioni.cpp)
        int calcolaDistanziamentoMedio() const;
        int calcolaDistanziamentoMassimoDocente(string docente) const;
        int calcolaDistanziamentoMinimoAula(string aula) const;
        
        //Metodi da non modificare
        void aggiungiLezione(Lezione* l) { lezioni.push_back(l); }
        void rimuoviLezione(Lezione* l) { lezioni.remove(l); }
        ~GestoreLezioni() { while(!lezioni.empty()) { delete lezioni.back(); lezioni.pop_back(); } }
    private:
        list<Lezione*> lezioni; 
};

#endif