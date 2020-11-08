#ifndef Mondiale_H
#define Mondiale_H

#include "Partita.h"

#include <iostream>
#include <list>
#include <vector>
using namespace std;

class Mondiale
{
    private:
        list<Partita> partite;        

    public:
        int metodo1();
        int metodo2();
        int metodo3();
        int metodo4();

    inline void aggiungi(Partita p) { partite.push_back(p); }    
};
#endif
