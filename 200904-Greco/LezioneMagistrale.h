#ifndef LEZIONE_MAGISTRALE_H
#define LEZIONE_MAGISTRALE_H

#include "Lezione.h"

class LezioneMagistrale : protected Lezione {

    public:
        LezioneMagistrale(string d, string a, int p) : Lezione(d,a,p) {}

        //Implementare qui il metodo calcolaDistanziamento calcolato come il numero di partecipanti alla lezione * 4.
        int calcolaDistanziamento(){
          return getPartecipanti()*4;
        }
};

#endif
