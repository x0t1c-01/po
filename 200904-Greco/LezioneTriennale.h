#ifndef LEZIONE_TRIENNALE_H
#define LEZIONE_TRIENNALE_H

#include "Lezione.h"

class LezioneTriennale : protected Lezione {

    public:
        LezioneTriennale(string d, string a, int p) : Lezione(d,a,p) {}

        //Implementare qui il metodo calcolaDistanziamento calcolato come il numero di partecipanti alla lezione * 2.
        int calcolaDistanziamento(){
          return getPartecipanti()*2;
        }
};

#endif
