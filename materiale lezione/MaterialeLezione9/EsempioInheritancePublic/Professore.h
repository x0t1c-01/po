#ifndef PROFESSORE_H
#define PROFESSORE_H

#include "Persona.h"

class Professore : public Persona {

    public:
        Professore();
        Professore(string cf, string n, string c, float s);
        
        float getStipendio() const;
        void setStipendio(float);
        
    private:
        float stipendio;
};

#endif