#include "Prodotto.h"

Prodotto::Prodotto() {
  id = 0;
  prezzo = 0.0;
}

int Prodotto::getId() const {
  return id;
}

void Prodotto::setId(int i) {
  id = i;
}

float Prodotto::getPrezzo() const {
  return prezzo;
}

void Prodotto::setPrezzo(float p) {
  prezzo = p;
}
