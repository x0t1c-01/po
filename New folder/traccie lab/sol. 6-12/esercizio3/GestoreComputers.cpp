
#include "GestoreComputers.h"

/*
Calcolare il massimo delle medie dei prezzi dei computers prodotti da ogni produttore.

Utilizzare la divisione intera.

Se non sono presenti computers, restituire -1.

*/
int GestoreComputers::calcolaMedia( string p){
 int somma=0;
 int cont;
    for(list<Computer>:: iterator it= computers.begin(); it!= computers.end();it++){
        if(it->getProduttore()== p){
        cont++;
        somma+= it->getPrezzo();
        }
    }
    return somma/cont;
}

int GestoreComputers::metodo1()
{
    if(computers.empty())
    return -1;

    vector<string> produttori;
    for(list<Computer>:: iterator it= computers.begin(); it!= computers.end();it++){
        if(find(produttori.begin(),produttori.end(),it->getProduttore()) == produttori.end()){
            produttori.push_back(it-> getProduttore());
        }
    }
    int max= INT_MIN;
    int ris=0;
    for(int i=0;i<produttori.size();i++){
      ris=calcolaMedia(produttori[i]);
        if(ris> max)
        max=ris;
    }
    return max;
}

/*
Determinare la mediana dei computers ottenuta considerando la seguente relazione d'ordine:

Un computer C1 precede un computer C2 se il prezzo di C1 e' minore del prezzo di C2 e a parita' di prezzo, il tipo di C1 precede il tipo di C2 (ULTRABOOK precede NETBOOK precede NOTEBOOK).

Restituire il prezzo del computer che si trova in corrispondenza della mediana.

Nel caso in cui non ci siano computers presenti nel gestore, restituire -1.

NOTA BENE: calcolare mediana nel seguente modo: dopo aver ordinato gli oggetti si prende quello presente nel mezzo (utilizzare la divisione intera).

*/
int GestoreComputers::metodo2()
{
    /* IMPLEMENTARE QUESTO METODO */
    return -1;
}

/*
Siano P1 e P2 produttori distinti tali per cui la somma dei prezzi di tutti i prodotti di P1 meno la somma dei prezzi di tutti i prodotti di P2 e' minima rispetto ad ogni altra coppia di produttori.
Determinare la posizione del primo produttore tra P1 e P2 in ordine di occorrenza nell'elenco.

Se non sono presenti computers o e' presente un solo produttore, restituire -1.

NOTA BENE: nel caso ci siano piu' coppie di produttori distinti che verificano la condizione, considerare il primo produttore in ordine di occorrenza nell'elenco che si trova in una di queste coppie.

*/
int GestoreComputers::metodo3()
{
    /* IMPLEMENTARE QUESTO METODO */
    return -1;
}

/*
Data la seguente definizione:
Un computer C1 e' connesso con un Computer C2 se:
- C1 e' connesso con C2, oppure
- C1 e' connesso con C3 e C3 e' connesso con C2.

Il metodo deve restituire il numero massimo di computer connessi tra loro.

Nel caso in cui non ci siano computers restituisce -1.

*/
int GestoreComputers::metodo4()
{
    /* IMPLEMENTARE QUESTO METODO */
    return -1;
}
