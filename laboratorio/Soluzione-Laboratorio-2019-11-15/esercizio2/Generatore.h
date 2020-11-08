#ifndef GENERATORE_H
#define GENERATORE_H

#include <list>
#include <ctime>
#include <iostream>
using namespace std;

class Generatore {

    public:
        Generatore() { srand(time(NULL)); }
        int generaNumero();
        int numeroFrequente() const;
        int generaNumeroPrimo () const;
        void cancellaNumero(int num, int n);

        friend ostream& operator<<(ostream& o, const Generatore& g) {
            o << "[";
            for(auto elem : g.numeri)
                o << " " << elem;
            o << " ]";
            return o;
        }
    private:
        list<int> numeri;
};

#endif