#include "CodaEreditaria.h"
#include <iostream>
#include <vector>
using namespace std;

int main() {
    CodaEreditaria coda;
    
    vector<char> elementi = { 'v', 'v', 's', 'r', 'p', 'v', 'r', 'p', 't', 't', 't', 't', 'g', 'g', 'g', 'p', 'g'};
    for(auto e : elementi)
        coda.aggiungi(e);

    while(coda.size() != 0) {
        cout << coda.prossimo() << endl;
        coda.rimuovi();
    }
    
    return 0;
}