#ifndef LEZIONE_TRIENNALE_H
#define LEZIONE_TRIENNALE_H

#include "Lezione.h"

class LezioneTriennale : public Lezione {

    public:
        LezioneTriennale(string d, string a, int p) : Lezione(d,a,p) {}
        int calcolaDistanziamento(){return partecipanti*2;}
        //Implementare qui il metodo calcolaDistanziamento calcolato come il numero di partecipanti alla lezione * 2.
};

#endif
