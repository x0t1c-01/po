#include "GestoreLezioni.h"
#include "Lezione.h"
#include "LezioneMagistrale.h"
#include "LezioneTriennale.h"

#include <iostream>
#include <vector>
using namespace std;

int main() {    
    GestoreLezioni g;
    string docenti[4] = {"d1", "d2", "d3", "d4"};
    string aule[4] = {"a1", "a2", "a3", "a4"};
    vector<int> risultati;
    
    risultati.push_back(g.calcolaDistanziamentoMedio());
    for(int i = 0; i < 20; i++) { 
        g.aggiungiLezione(new LezioneTriennale(docenti[i%4], aule[i%4], i*12));    
        g.aggiungiLezione(new LezioneMagistrale(docenti[i%4], aule[i%4], i*5));
    }
    
    risultati.push_back(g.calcolaDistanziamentoMedio());
    for(int i = 0; i < 4; i++) {
        risultati.push_back(g.calcolaDistanziamentoMassimoDocente(docenti[i]));
        risultati.push_back(g.calcolaDistanziamentoMinimoAula(aule[i]));
    }
    risultati.push_back(g.calcolaDistanziamentoMassimoDocente("d5"));
    risultati.push_back(g.calcolaDistanziamentoMinimoAula("a5"));
    
    for(int i = 0; i < risultati.size(); i++) {
        cout << risultati[i];
    }
    cout << endl;
    
    //Risultato atteso: -12093840408204324045660-1-1
}