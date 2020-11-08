#include "GestorePersone.h"
#include <list>
#include <iostream>
using namespace std;

int main() {

    GestorePersone g;
    g.aggiungiStudente("cf3", "nome3", "cognome3", 1.0);
    g.aggiungiStudente("cf4", "nome4", "cognome4", 2.0);
    g.aggiungiProfessore("cf1", "nome1", "cognome1", 1.0);
    g.aggiungiProfessore("cf2", "nome2", "cognome2", 2.0);
    
    GestorePersone g1;
    g1.aggiungiStudente("cf5", "nome3", "cognome3", 1.0);
    g1.aggiungiStudente("cf6", "nome4", "cognome4", 2.0);
    g1.aggiungiProfessore("cf7", "nome1", "cognome1", 1.0);
    g1.aggiungiProfessore("cf8", "nome2", "cognome2", 2.0);
    
    g1 = g;
    cout << "Indirizzo persona cf3 in g: " << g.getPersona("cf3") << endl;
    cout << "Indirizzo persona cf3 in g1: " << g1.getPersona("cf3") << endl;    

    return 0;
}
