#ifndef LEZIONE_TRIENNALE_H
#define LEZIONE_TRIENNALE_H

//  189709 - Bueti Giovanni Serafino

#include "Lezione.h"

class LezioneTriennale : public Lezione {
    
    public:
        LezioneTriennale(string d, string a, int p) : Lezione(d,a,p) {}
        
        //Implementare qui il metodo calcolaDistanziamento calcolato come il numero di partecipanti alla lezione * 2.
        int calcolaDistanziamento() const override {
            return getPartecipanti() * 2;
        }
};

#endif