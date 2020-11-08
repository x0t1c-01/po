#ifndef STUDENTE_H
#define STUDENTE_H

#include "Persona.h"

class Studente : public Persona {

    public:
        Studente();
        Studente(string cf, string n, string c, float is);
        
        float getIsee() const;
        void setIsee(float);
        
    private:
        float isee;
};

#endif