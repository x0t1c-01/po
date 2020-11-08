#include <iostream>
using namespace std;

#include "GestoreProdotti.h"
#include "Supermercato.h"

void stampaMenu() {
    cout << "==== Menu ====" << endl;
    cout << "  Premi 1 per creare un prodotto" << endl;
    cout << "  Premi 2 per modificare un prodotto" << endl;
    cout << "  Premi 3 per aggiungere un prodotto all'interno del supermercato" << endl;
    cout << "  Premi 4 per rimuovere un prodotto dal supermercato" << endl;
    cout << "  Premi 5 per rimuovere tutti i prodotti dal supermercato" << endl;
    cout << "  Premi 6 per stampare tutti i prodotti nel supermercato" << endl;
    cout << "  Premi 7 per stampare i prodotti economici" << endl;
    cout << "  Premi 9 per uscire" << endl;
}

int main() {
    int scelta = 0;
    GestoreProdotti g;
    Supermercato s;        
    do {
        stampaMenu();
        cin >> scelta;    
        switch(scelta) {
            case 1: {
                int id; string descrizione; float prezzo;
                cout << "Inserisci id" << endl;
                cin >> id;
                cout << "Inserisci descrizione" << endl;
                cin >> descrizione;
                cout << "Inserisci prezzo" << endl;
                cin >> prezzo;
                if(g.aggiungiProdotto(id, descrizione, prezzo))
                    cout << "Prodotto inserito con successo!" << endl;
                else
                    cout << "Prodotto presente!" << endl; 
                }
                break;
            case 2: {
                int id; string descrizione; float prezzo;
                cout << "Inserisci id" << endl;
                cin >> id;
                if(g.getProdotto(id) != nullptr) {
                    cout << "Inserisci descrizione" << endl;
                    cin >> descrizione;
                    cout << "Inserisci prezzo" << endl;
                    cin >> prezzo;
                    if(g.modificaProdotto(id, descrizione, prezzo))
                        cout << "Prodotto modificato con successo!" << endl;
                }
                else
                    cout << "Prodotto non presente!" << endl;
                }
                break;
            case 3: {  
                int id;
                cout << "Inserisci id" << endl;
                cin >> id;
                Prodotto* p = g.getProdotto(id);
                if(p != nullptr)
                    s.aggiungiProdotto(p);
                else
                    cout << "Prodotto non presente!" << endl;
                }
                break;
            case 4: {
                int id;
                cout << "Inserisci id" << endl;
                cin >> id;
                Prodotto* p = g.getProdotto(id);
                if(p != nullptr)
                    s.rimuoviProdotto(p);
                else
                    cout << "Prodotto non presente!" << endl;
                }
                break;
            case 5:   
                s.svuota();
                break;
            case 6:   
                s.stampaInventario();
                break;
            case 7: { 
                int n;
                cout << "Quanti prodotti economici vuoi stampare?" << endl;
                cin >> n;
                s.prodottiEconomici(n);
                }
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