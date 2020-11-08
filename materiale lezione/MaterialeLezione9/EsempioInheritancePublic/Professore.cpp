#include "Professore.h"

Professore::Professore() : Persona() {    
    stipendio = 0.0;
}

Professore::Professore(string cf, string n, string c, float s) : Persona(cf, n, c) {
    stipendio = s;
}

float Professore::getStipendio() const {
    return stipendio;
}

void Professore::setStipendio(float s) {
    stipendio = s;
}
