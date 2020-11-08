#include "CodaPrioritaria.h"
#include <iostream>
#include <vector>
using namespace std;

int main() {
    CodaPrioritaria coda;
    
    vector<int> elementi = {3, 1, 5, -1, -6, -3, 2, 4, -8};
    for(int e : elementi)
        coda.aggiungi(e);

    while(coda.size() != 0) {
        cout << coda.prossimoNumero() << endl;
        coda.rimuoviProssimoNumero();
    }
    
    return 0;
}