#ifndef GESTORE_PERSONE_H
#define GESTORE_PERSONE_H

#include <list>
using namespace std;

#include "Persona.h"
#include "Professore.h"
#include "Studente.h"

class GestorePersone {
    
    public:
        GestorePersone() {}
        void aggiungiStudente(string cf, string n, string c, float isee) {
            Studente* s = new Studente(cf, n, c, isee);
            if(getPersona(cf)==nullptr) //Se è già presente una persona con quel codice fiscale non deve essere inserita
                persone.push_back(s);
        }
        
        void aggiungiProfessore(string cf, string n, string c, float stipendio) {
            Professore* p = new Professore(cf, n, c, stipendio);
            if(getPersona(cf)==nullptr) //Se è già presente una persona con quel codice fiscale non deve essere inserita
                persone.push_back(p);            
        }
        
        Persona* getPersona(string cf) const {
            for(auto p : persone)
                if(p->getCodiceFiscale() == cf)
                    return p;
            return nullptr;        
        }
        
        ~GestorePersone() { clear(); }
        
        GestorePersone(const GestorePersone& g) {
            for(auto p : g.persone)
                persone.push_back(p->clone());
        }
        
        GestorePersone& operator=(const GestorePersone& g) {
            if(this != &g) {
                clear();
                for(auto p : g.persone)
                    persone.push_back(p->clone());
            }
            return *this;
        }
        
    private:
        void clear() {
            for(auto p : persone)
                delete p;
            persone.clear();
        }
        
        list<Persona*> persone;
};

#endif