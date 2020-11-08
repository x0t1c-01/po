#include "Persona.h"

Persona::Persona() {
    codiceFiscale = "";
    nome = "";
    cognome = "";   
}

Persona::Persona(string cf, string n, string c) {
    codiceFiscale = cf;
    nome = n;
    cognome = c;
}

void Persona::setCodiceFiscale(string cf) {
    codiceFiscale = cf;
}

void Persona::setNome(string n) {
    nome = n;
}

void Persona::setCognome(string c) {
    cognome = c;
}

string Persona::getCodiceFiscale() const {
    return codiceFiscale;
}

string Persona::getNome() const {
    return nome;
}

string Persona::getCognome() const {
    return cognome;
}
