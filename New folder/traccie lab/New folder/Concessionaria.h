#ifndef CONCESSIONARIA_H
#define CONCESSIONARIA_H

#include "Veicolo.h"
#include <list>

class Concessionaria(){

private:
    list<Veicolo> Automobili;

public:
    double PrezzoScont(string targa);




    inline bool aggiungi(Veicolo a) {Automobili.push_back(a); return true};
    inline bool rimuovi(Veicolo b) {Automobili.pop_back(b); return true};
#endif
