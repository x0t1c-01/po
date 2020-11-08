#ifndef CODA_EREDITARIA_H
#define CODA_EREDITARIA_H

#include <list>
#include <iostream>
using namespace std;

#include "Studente.h"

class CodaEreditaria : private list<Studente> {
    public:
        void aggiungi(Studente s);
        Studente prossimo() const;
        void rimuovi();
        unsigned int size() const;        
};

#endif