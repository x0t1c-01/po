#include "Studente.h"

Studente::Studente() : Persona() {    
    isee = 0.0;
}

Studente::Studente(string cf, string n, string c, float is) : Persona(cf,n,c), isee(is) {    
}

float Studente::getIsee() const {
    return isee;
}

void Studente::setIsee(float is) {
    isee = is;
}