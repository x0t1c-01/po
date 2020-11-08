#include "Rubrica.h"

#include <iostream>
using namespace std;

int main() {
    Rubrica r;
    r.aggiungiNumero("a", "1");    
    r.aggiungiNumero("b", "1");
    r.aggiungiNumero("c", "4");
    r.aggiungiNumero("d", "1");
    r.aggiungiNumero("e", "1");
    r.stampa();
    
    cout << r.getNumero("c") << endl;
    
    r.modificaNumero("c","3");
    r.stampa();
    return 0;
}