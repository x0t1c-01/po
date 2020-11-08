#ifndef VEICOLO_H
#define VEICOLO_H

#include <iostream>
using namespace std;

class Veicolo {
    public:
        Veicolo(string t, float p, string c, string n) : targa(t), prezzo(p), casaProduttrice(c), nomeVeicolo(n) {}
        virtual ~Veicolo() {}
        string getTarga() const { return targa; }
        virtual float getPrezzo() const { return prezzo; }
        string getCasaProduttrice() const { return casaProduttrice; }
        string getNomeVeicolo() const { return nomeVeicolo; }
        
        virtual Veicolo* clone() const { return new Veicolo(*this); }
        
        friend ostream& operator<<(ostream& o, const Veicolo& v) {
            o << "[" << v.targa << "] - " << v.casaProduttrice << " " << v.nomeVeicolo << ", " << v.getPrezzo() << "€";
            return o;
        }        
        
    private:
        string targa;
        float prezzo;
        string casaProduttrice;
        string nomeVeicolo;
};

#endif