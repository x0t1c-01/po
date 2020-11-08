#ifndef PROFESSORE_H
#define PROFESSORE_H

#include "Persona.h"

class Professore : public Persona {

    public:
        Professore() : Persona(), stipendio(0.0) {}
        Professore(string cf, string n, string c, float s) : Persona(cf, n, c), stipendio(s) {}
        
        virtual Professore* clone() const {
            return new Professore(*this);
        }
        
        float getStipendio() const { return stipendio; }
        void setStipendio(float s) { stipendio = s; }
        
    private:
        float stipendio;
};

#endif
