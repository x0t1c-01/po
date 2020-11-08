#ifndef PAZIENTE_H
#define PAZIENTE_H

#include <string>
#include <iostream>
using namespace std;

class Paziente {
  public:
    Paziente(int c, int e, int n, string t) : codice(c), eta(e), numero(n), tipologia(t) {}
    int getCodice() const { return codice; }
    int getEta() const { return eta; }
    int getNumero() const { return numero; }
    string getTipologia() const { return tipologia; }
    
    friend ostream& operator<<(ostream& o, const Paziente& p) {
        o << "[Cod. " << p.codice << ", " << p.eta << " anni, num. " << p.numero << ", " << p.tipologia << "]";
        return o; 
    }
  
  private:
    int codice;
    int eta;
    int numero;
    string tipologia;
};

#endif