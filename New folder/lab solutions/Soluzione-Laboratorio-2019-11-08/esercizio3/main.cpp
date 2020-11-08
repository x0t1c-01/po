#include "Carriera.h"
#include "Esame.h"

#include <iostream>
using namespace std;

int main() {
    Esame* e1 = new Esame("esame1", "professore1", 31, 10);
    Esame* e2 = new Esame("esame2", "professore2", 28, 20);
    Esame* e3 = new Esame("esame3", "professore1", 45, 10);
    Esame* e4 = new Esame("esame4", "professore2", 31, 20);
    Esame* e5 = new Esame("esame5", "professore1", 31, 20);
    
    Carriera c;
    c.aggiungi(e1);
    c.aggiungi(e2);
    c.aggiungi(e3);
    c.aggiungi(e4);
    c.aggiungi(e5);
    
    cout << c.mediaVoti() << endl;
    c.stampa();
    c.stampa("professore2");
    c.stampaEsamiMigliori();
    if(c.borsaDiStudio()) 
        cout << "Borsa di studio" << endl;
    else
        cout << "Non borsa di studio" << endl;
    c.ordinaPerVoto();
    c.stampa();    
    c.ordinaPerNome();
    c.stampa();
    
    delete e1;
    delete e2;
    delete e3;
    delete e4;
    delete e5;
}