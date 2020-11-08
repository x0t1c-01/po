#ifndef RIFIUTO_H
#define RIFIUTO_H

#include <string>
#include <iostream>
using namespace std;

class Rifiuto {
    public:
        virtual ~Rifiuto() {}
        Rifiuto(string a, float q) : azienda(a), quantita(q) {}
        virtual void smaltisci() const = 0;
        friend ostream& operator<<(ostream& o, const Rifiuto& r) {
            o << r.azienda << ", " << r.quantita;
            return o;
        }
        
        string getAzienda() const { return azienda; }
        float getQuantita() const { return quantita; }
    
    private:
        string azienda;
        float quantita;
};

#endif