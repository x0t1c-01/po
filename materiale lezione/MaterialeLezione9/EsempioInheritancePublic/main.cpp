#include "Professore.h"
#include "Studente.h"
#include <list>
#include <iostream>
using namespace std;

int main() {

    Professore* p1 = new Professore("cf1", "nome1", "cognome1", 1.0);
    Professore* p2 = new Professore("cf2", "nome2", "cognome2", 2.0);
    Studente* s1 = new Studente("cf3", "nome3", "cognome3", 1.0);
    Studente* s2 = new Studente("cf4", "nome4", "cognome4", 2.0);
    
    /* Codice senza inheritance
    list<Professore*> professori;
    list<Studente*> studenti;
    professori.push_back(p1);
    professori.push_back(p2);
    studenti.push_back(s1);
    studenti.push_back(s2);
    for(auto p : professori)
        cout << p->getCf() << endl;
    for(auto s : studenti)
        cout << s->getCf() << endl;
    */  
    
    list<Persona*> universitari;
    universitari.push_back(p1);
    universitari.push_back(p2);
    universitari.push_back(s1);
    universitari.push_back(s2);
    
    for(auto p : universitari)
        cout << p->getCodiceFiscale() << " " << p->getNome() << " " << p->getCognome() << endl;
    
    delete p1;
    delete p2;
    delete s1;
    delete s2;
    return 0;
}