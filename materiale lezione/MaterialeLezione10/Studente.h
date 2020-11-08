#ifndef STUDENTE_H
#define STUDENTE_H

#include "Persona.h"

class Studente : public Persona {

    public:
        Studente() : Persona(), isee(0.0) {}
        Studente(string cf, string n, string c, float is) : Persona(cf,n,c), isee(is) {}    
        
        Studente* clone() const {
            return new Studente(*this);
        }
        
        float getIsee() const { return isee; }
        void setIsee(float is) { isee = is; }
        
    private:
        float isee;
};

#endif
