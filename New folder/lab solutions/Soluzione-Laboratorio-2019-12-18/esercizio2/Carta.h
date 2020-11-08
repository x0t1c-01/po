#ifndef CARTA_H
#define CARTA_H

#include "Rifiuto.h"
#include <iostream>
using namespace std;

class Carta : public Rifiuto {
    public:
        Carta(string a, float q) : Rifiuto(a,q) {}
        void smaltisci() const { cout << "Smaltimento carta: " << getAzienda() << ", " << getQuantita() << " kg" << endl; }
};

#endif