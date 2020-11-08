#include "Generatore.h"
#include <iostream>
using namespace std;

int main() {
    Generatore g;
    for(int i = 0; i < 100; i++)
        cout << "Genero: " << g.generaNumero() << endl;
    
    cout << g << endl;
    
    cout << "Numero frequente " << g.numeroFrequente() << endl;
    cout << "Numero primo " << g.generaNumeroPrimo() << endl;

    int n;
    int occ;
    cout << "Inserisci numero da cancellare" << endl;
    cin >> n;
    cout << "Quante occorrenze di " << n << " vuoi cancellare?" << endl;
    cin >> occ;        
    g.cancellaNumero(n, occ);
    if(occ <= 0)
        cout << "Numero non eliminato" << endl;
    else
        cout << "Numero eliminato" << endl;
    
    cout << g << endl;
    return 0;
}