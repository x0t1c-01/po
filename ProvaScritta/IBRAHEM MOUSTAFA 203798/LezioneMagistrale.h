#ifndef LEZIONE_MAGISTRALE_H
#define LEZIONE_MAGISTRALE_H

#include "Lezione.h"

class LezioneMagistrale : public Lezione {

    public:
        LezioneMagistrale(string d, string a, int p) : Lezione(d,a,p) {}
        int calcolaDistanziamento(){return partecipanti*4;}
        //Implementare qui il metodo calcolaDistanziamento calcolato come il numero di partecipanti alla lezione * 4.
};

#endif
