#ifndef PRODOTTO_H
#define PRODOTTO_H

#include <iostream>
using namespace std;

class Prodotto {
    
    public:
        Prodotto(int id, string descrizione, float prezzo);
        void setDescrizione(string descr);
        void setPrezzo(float prezzo);
        int getId() const;
        string getDescrizione() const;
        float getPrezzo() const;        
        bool operator==(const Prodotto& p) const;
        
        friend ostream& operator<<(ostream& o, const Prodotto& p) {
            o << p.id << ": " << p.descrizione << " --- " << p.prezzo << "€";
            return o;
        }        
        
    private:
        int id;
        string descrizione;
        float prezzo;

};

#endif