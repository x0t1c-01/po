#include <iostream>
using namespace std;

#include "GestorePrenotazioni.h"

void stampaMenu() {
    cout << "==== Menu ====" << endl;
    cout << "  Premi 1 per aggiungere una prenotazione" << endl;
    cout << "  Premi 2 per rimuovere una prenotazione" << endl;
    cout << "  Premi 3 per stampare le prenotazioni relative ad un codice" << endl;
    cout << "  Premi 4 per ordinare le prenotazioni" << endl;
    cout << "  Premi 9 per uscire" << endl;
}

int main() {
    int scelta = 0;
    GestorePrenotazioni gp;    
    do {
        stampaMenu();
        cin >> scelta;    
        switch(scelta) {
            case 1: {
                int posti;
                cout << "Inserisci il numero di posti" << endl;
                cin >> posti;
                
                while(posti <= 0) {
                    cout << "Inserisci un valore valido per il numero di posti (>0)" << endl;
                    cin >> posti;
                }
                  
                string codice;                
                cout << "Inserisci il codice" << endl;
                cin >> codice;
                if(gp.aggiungiPrenotazione(posti, codice))
                    cout << "Prenotazione effettuata con successo" << endl;
                else
                    cout << "Codice errato o numero di posti non sufficienti" << endl;
                }
                break;
            case 2: {
                int n;
                cout << "Inserisci numero prenotazione da rimuovere" << endl;
                cin >> n;                
                if(gp.rimuoviPrenotazione(n))
                    cout << "Prenotazione rimossa" << endl;
                else
                    cout << "Prenotazione non trovata" << endl;
            }
                break;            
            case 3: {
                string codice;
                cout << "Inserisci il codice delle prenotazioni che vuoi stampare" << endl;
                cin >> codice;
                gp.stampaPrenotazioni(codice);
            }
                break;
            case 4:
                gp.ordinaPrenotazioni();                
                break;
            case 9:   
                cout << "Grazie e a presto!" << endl;
                break;
            default:   
                cout << "Scelta non valida" << endl;
                break;            
        }        
    } while(scelta != 9);
    
    return 0;
}