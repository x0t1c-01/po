#include "Vettori.h"

int main() {
    Vettori v;
    for(int i = 0; i < 10; i++)
        v.aggiungi(i);
    v.aggiungi('b');
    v.aggiungi('a');
    v.aggiungi('a');
    v.aggiungi('a');
    v.aggiungi('a');
    v.aggiungi('a');
    v.aggiungi('b');
    v.aggiungi('c');
    v.aggiungi('b');
    v.aggiungi('a');
    v.aggiungi('a');
    v.genera();
    v.stampa();

    v.rimuoviMinori(5);
    v.rimuoviCarattere('a');
    v.stampa();
    return 0;
}
