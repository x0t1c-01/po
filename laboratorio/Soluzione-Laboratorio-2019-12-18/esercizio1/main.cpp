#include <iostream>
#include <string>
using namespace std;

#include "Laboratorio.h"
#include "Paziente.h"

int main() {
    vector<Paziente*> pazienti;
    for(int i = 0; i < 10; i++) {
        pazienti.push_back(new Paziente((i%4)+1, (i+4)*5, 10-i, "tipo"+to_string(i)));        
    }
    
    Laboratorio l;    
    for(auto p : pazienti)
        l.add(p);
    while(l.size() != 0) {
        cout << "Prossimo paziente: " << *l.next() << endl;
        l.remove();
    }

    for(auto p : pazienti)
        delete p;        
}