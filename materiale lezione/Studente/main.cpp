#include "Studente.h"

#include <iostream>
using namespace std;

int main() {
    Studente s1;
    s1.setMatricola(999);
    s1.setEta(19);
    s1.setNome("Maria");
    s1.setCognome("Bianchi");

    cout << "Studente: " << s1.getNome() << " " << s1.getCognome() << endl;

    Studente s2(1000, 19, "Mario","Rossi");
    cout << "Studente: " << s2.getNome() << " " << s2.getCognome() << endl;
}
