#include "Studente.h"

Studente::Studente(){
    matricola = 0;
    eta = 0;
    nome = "";
    cognome = "";
}

Studente::Studente(unsigned int matr, unsigned int e, string nome, string c) {
    matricola = matr;
    eta = e;
    this->nome = nome;
    cognome = c;
}

unsigned int Studente::getMatricola() const {
    return matricola;
}

unsigned int Studente::getEta() const {
    return eta;
}

string Studente::getNome() const {
    return nome;
}

string Studente::getCognome() const {
    return cognome;
}

void Studente::setMatricola(unsigned int matr) {
    matricola = matr;
}

void Studente::setEta(unsigned int e) {
    eta = e;
}

void Studente::setNome(string n) {
    nome = n;
}

void Studente::setCognome(string c) {
    cognome = c;
}
