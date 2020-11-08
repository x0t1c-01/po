#ifndef GESTORE_PRENOTAZIONI_H
#define GESTORE_PRENOTAZIONI_H

#include <list>
#include <vector>
#include <string>
using namespace std;
#include "Prenotazione.h"

class GestorePrenotazioni {
    
    public:
        GestorePrenotazioni();
        bool aggiungiPrenotazione(int posti, string codice);
        bool rimuoviPrenotazione(int numero);
        void stampaPrenotazioni(string codice) const;
        void ordinaPrenotazioni();
        
        ~GestorePrenotazioni();
        GestorePrenotazioni& operator=(const GestorePrenotazioni&);
        GestorePrenotazioni(const GestorePrenotazioni&);
        
    private:
        list<Prenotazione*> prenotazioni;
        bool esistePrenotazione(int n);
        
        class CodicePrenotazione {
            public:
                CodicePrenotazione() {}
                
                int postiDisponibili(string codice) {
                    for(int i = 0; i < codici.size(); i++) {
                        if(codici[i]==codice)
                            return postiTotali[i];
                    }
                    return -1;
                }
                
                bool occupaPosti(int posti, string codice) {
                    for(int i = 0; i < codici.size(); i++) {
                        if(codici[i]==codice && postiTotali[i] >= posti) {
                            postiTotali[i] -= posti;
                            return true;
                        }
                    }
                    return false;
                }
                
                bool liberaPosti(int posti, string codice) {
                    for(int i = 0; i < codici.size(); i++) {
                        if(codici[i]==codice) {
                            postiTotali[i] += posti;
                            return true;
                        }
                    }
                    return false;
                }
            private:
                vector<string> codici = {"a0001", "b0002", "c0003", "d0004", "e0005", "f0006", "g0007", "h0008", "i0009", "z0010"};
                vector<int> postiTotali = {1,2,3,4,5,6,7,8,9,10};                              
        };
        CodicePrenotazione cp;
};

#endif