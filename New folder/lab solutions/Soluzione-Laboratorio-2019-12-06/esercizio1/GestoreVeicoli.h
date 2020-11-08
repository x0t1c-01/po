#ifndef GESTORE_VEICOLI_H
#define GESTORE_VEICOLI_H

#include "Veicolo.h"
#include "Automobile.h"
#include "Moto.h"

class GestoreVeicoli {
    
    public:
        GestoreVeicoli() {}
        
        void aggiungiAutomobile(string t, float p, string c, string n) {
            Automobile* a = new Automobile(t, p, c, n);
            aggiungiVeicolo(a);
        }
        
        void aggiungiMoto(string t, float p, string c, string n) {
            Moto* m = new Moto(t, p, c, n);
            aggiungiVeicolo(m);
        }
        
        Veicolo* getVeicolo(string targa) {
            for(auto v : veicoli)
                if(v->getTarga() == targa)
                    return v;
            return nullptr;
        }
        
        ~GestoreVeicoli() {
            clear();
        }
        
        GestoreVeicoli& operator=(const GestoreVeicoli& v) {
            if(this != &v) {
                clear();
                for(auto e : v.veicoli) {
                    veicoli.push_back(e->clone()); 
                }
            }
            return *this;
        }
        
        GestoreVeicoli(const GestoreVeicoli& v) {
            for(auto e : v.veicoli) {
                veicoli.push_back(e->clone()); 
            }
        }
        
    private:
        void clear() {
            while(!veicoli.empty()) {
                delete veicoli.back();
                veicoli.pop_back();
            }            
        }
        
        void aggiungiVeicolo(Veicolo* v) {
            for(auto e : veicoli) {
                if(v->getTarga() == e->getTarga())
                    return;
            }
            veicoli.push_back(v);
        }
        
        list<Veicolo*> veicoli;
};

#endif