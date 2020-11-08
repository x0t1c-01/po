#include "Prodotto.h"

Prodotto::Prodotto(int id, string descrizione, float prezzo) {
    this->id = id;
    this->descrizione = descrizione;
    this->prezzo = prezzo;
}

void Prodotto::setDescrizione(string descr) {
    descrizione = descr;
}
void Prodotto::setPrezzo(float pr) {
    prezzo = pr;
}

int Prodotto::getId() const {
    return id;
}

string Prodotto::getDescrizione() const {
    return descrizione;
}

float Prodotto::getPrezzo() const {
    return prezzo;
}

bool Prodotto::operator==(const Prodotto& p) const {
    return id == p.id;
}