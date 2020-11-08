#include "CodaEreditaria.h"
#include <iostream>
#include <vector>
using namespace std;

#include "Studente.h"

int main() {
    Studente s1(10, 12.0, 25.0);
    Studente s2(11, 11.0, 24.0);
    Studente s3(12, 7.0, 28.2);
    Studente s4(13, 3.0, 29.8);
    Studente s5(25, 18.0, 26.0);
    Studente s6(7, 18.0, 27.0);
    Studente s7(8, 19.0, 27.8);
    
    CodaEreditaria coda;
    
    vector<Studente> elementi = {s1, s2, s3, s4, s5, s6, s7};
    for(auto e : elementi) {
        coda.aggiungi(e);
    }

    while(coda.size() != 0) {
        cout << coda.prossimo() << endl;
        coda.rimuovi();
    }
    
    return 0;
}
