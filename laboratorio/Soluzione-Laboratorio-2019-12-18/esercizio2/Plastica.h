#ifndef PLASTICA_H
#define PLASTICA_H

#include "Rifiuto.h"
#include <iostream>
using namespace std;

class Plastica : public Rifiuto {
    public:
        Plastica(string a, float q) : Rifiuto(a,q) {}
        void smaltisci() const { cout << "Smaltimento plastica: " << getAzienda() << ", " << getQuantita() << " kg" << endl; }
};

#endif