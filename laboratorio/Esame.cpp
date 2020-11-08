#include "Esame.h"

Esame::Esame(string n, string p, int v, int c) {
    nome = n;
    professore = p;
    voto = v;
    crediti = c;
}

string Esame::getNome() const {
    return nome;
}

string Esame::getProfessore() const {
    return professore;
}

int Esame::getVoto() const {
    return voto;
}

int Esame::getCrediti() const {
    return crediti;
}