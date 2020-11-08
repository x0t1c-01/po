#include "Rifiuto.h"
#include "Plastica.h"
#include "Carta.h"

int main() {
    Rifiuto* r1 = new Plastica("azienda1", 220.5);
    Rifiuto* r2 = new Carta("azienda2", 100.0);
    r1->smaltisci(); // Stampa attesa: Smaltimento plastica: azienda1, 220.5 kg
    r2->smaltisci(); // Stampa attesa: Smaltimento carta: azienda2, 100.0 kg
    cout << *r1 << endl; // Stampa attesa: azienda1, 220.5
    cout << *r2 << endl; // Stampa attesa: azienda2, 100.0  
    delete r1;
    delete r2;
    return 0;
}

