#ifndef LEZIONE_MAGISTRALE_H
#define LEZIONE_MAGISTRALE_H

//  189709 - Bueti Giovanni Serafino

#include "Lezione.h"

class LezioneMagistrale : public Lezione {
    
    public:
        LezioneMagistrale(string d, string a, int p) : Lezione(d,a,p) {}        

        //Implementare qui il metodo calcolaDistanziamento calcolato come il numero di partecipanti alla lezione * 4.
        int calcolaDistanziamento() const override {
            return getPartecipanti() * 4;
        }   
};

#endif