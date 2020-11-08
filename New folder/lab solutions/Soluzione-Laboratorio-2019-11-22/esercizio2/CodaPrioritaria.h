#ifndef CODA_PRIORITARIA_H
#define CODA_PRIORITARIA_H

#include <list>
using namespace std;

class CodaPrioritaria {
    public:
        void aggiungi(int n);
        int prossimoNumero() const;
        void rimuoviProssimoNumero();
        int size() const;

    private:
        list<int> elementi;    
    
};

#endif