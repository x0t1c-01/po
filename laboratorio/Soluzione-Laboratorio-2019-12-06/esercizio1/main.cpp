#include <iostream>
using namespace std;

#include "Concessionaria.h"
#include "GestoreVeicoli.h"

void stampaMenu() {
    cout << "==== Menu ====" << endl;
    cout << "  Premi 1 per aggiungere un'automobile" << endl;
    cout << "  Premi 2 per aggiungere una moto" << endl;
    cout << "  Premi 3 per aggiungere un veicolo alla concessionaria" << endl;
    cout << "  Premi 4 per rimuovere un veicolo dalla concessionaria" << endl;
    cout << "  Premi 5 per stampare il prezzo scontato di un veicolo" << endl;
    cout << "  Premi 6 per stampare tutti i veicoli presenti nella concessionaria" << endl;
    cout << "  Premi 9 per uscire" << endl;
}

void leggiVeicolo(string& targa, float& prezzo, string& casa, string& nome) {
    cout << "Inserisci la targa, il prezzo, la casa produttrice e il nome del veicolo separati da spazio: ";
    cin >> targa;
    cin >> prezzo;
    cin >> casa;
    cin >> nome;
}

int main() {
    int scelta = 0;
    Concessionaria c;
    GestoreVeicoli g;
    do {
        stampaMenu();
        cin >> scelta;    
        switch(scelta) {
            case 1: {
                string t, c, n;
                float p;
                leggiVeicolo(t,p,c,n);
                g.aggiungiAutomobile(t,p,c,n);
            }                
                break;
            case 2: {
                string t, c, n;
                float p;
                leggiVeicolo(t,p,c,n);
                g.aggiungiMoto(t,p,c,n);                
            }
                break;
            case 3: {
                string t;
                cout << "Inserisci la targa del veicolo: ";
                cin >> t;
                Veicolo* v = g.getVeicolo(t);
                if(v != nullptr) {
                    if(c.aggiungi(v))
                        cout << "Veicolo aggiunto con successo!" << endl;
                    else
                        cout << "Veicolo già presente!" << endl;
                }
                else
                    cout << "Veicolo non trovato!" << endl;
            }
                break;
            case 4: {
                string t;
                cout << "Inserisci la targa del veicolo: ";
                cin >> t;
                if(c.rimuovi(t))
                    cout << "Veicolo rimosso con successo!" << endl;
                else
                    cout << "Veicolo non presente!" << endl;
            }
                break;
            case 5: {
                string t;
                cout << "Inserisci la targa del veicolo: ";
                cin >> t;
                c.stampaPrezzo(t);
            }
                break;
            case 6:
                c.stampa();
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