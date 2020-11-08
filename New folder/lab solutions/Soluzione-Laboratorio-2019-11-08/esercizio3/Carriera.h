#ifndef CARRIERA_H
#define CARRIERA_H

#include "Esame.h"
#include <list>
using namespace std;

class Carriera {
    public:
        void aggiungi(Esame*);
        float mediaVoti() const;
        void stampa() const;
        void stampa(string professore) const;
        void stampaEsamiMigliori() const;
        void ordinaPerVoto();
        void ordinaPerNome();
        bool borsaDiStudio() const;
        
    private:
        list<Esame*> esami;
};

#endif