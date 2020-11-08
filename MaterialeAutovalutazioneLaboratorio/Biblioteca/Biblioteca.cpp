
#include "Biblioteca.h"

/*
Sia A l'autore che ha scritto piu' libri nella biblioteca.
(Se piu' autori hanno questa proprieta', prendere il primo
di questi che compare nella biblioteca.)
Restituire la somma dei prezzi di tutti i libri scritti da A.

Se non sono presenti libri nella biblioteca, restituire -1.

*/
int Biblioteca::metodo1()
{
    if(biblioteca.empty()){
        return -1;
    }
    vector<string> autori;
    for(auto it: biblioteca){
        if(find(autori.begin(),autori.end(),it.getAutore())==autori.end()){
            autori.push_back(it.getAutore);
        }
    }
    vector<int> conta;
    for(int i=0;i<autori.size();i++){
        for(auto it: biblioteca){
            if(autori[i]==it.getAutore())
                conta[i]+=1;
        }
    }
int max=-1,pos;
    for(int i=0;i<conta.size();i++){
        if(conta[i]>max)
            max=conta[i];
            pos=i;
    }
int somma=0;
    for(auto it: biblioteca){
        if(it.getAutore()==autori[pos]){
            somma+=it.getPrezzo();
        }
    }
    return somma;


}

/*
Determinare la mediana dei libri ottenuta considerando la seguente relazione d'ordine:

Un libro L1 precede un libro L2 se il prezzo di L1 e' minore del prezzo di L2 e a parita' di prezzo, il tipo di L1 precede il tipo di L2 (NARRATIVA precede GIALLO precede SAGGISTICA).

Restituire il prezzo del libro che si trova in corrispondenza della mediana.

Nel caso in cui non ci siano libri presenti nella biblioteca, restituire -1.

NOTA BENE: calcolare mediana nel seguente modo: dopo aver ordinato gli oggetti in modo crescente,
si prende quello presente nel mezzo (utilizzare la divisione intera: size/2).

*/
bool biblioteca::ordina(Libro& a,Libro& b){
    if(a.getPrezzo()<b.getPrezzo())
        return true;
    if(a.getPrezzo()==b.getPrezzo()){
        if(a.getTipo()<b.getTipo())
            return true;
    }
    return false;
}
int Biblioteca::metodo2()
{
    if(biblioteca.empty())
        return -1;
    biblioteca.sort(ordina);
    for(auto it:biblioteca){
        if(it==biblioteca.size()/2)
            return it.getPrezzo();
    }
}

/*
Data la seguente definizione:
Un libro L1 ha un riferimento ad un Libro L2 se:
- L1 ha un riferimento a L2, oppure
- L1 ha un riferimento a C3 e C3 ha un riferimento a C2.

Sia L il libro con il piu' alto numero di riferimenti, il metodo deve restituire il numero di libri con cui L ha un riferimento.

Nel caso in cui non ci siano libri nella biblioteca restituisce -1.

*/

int Biblioteca::metodo3()
{
    /* IMPLEMENTARE QUESTO METODO */
    return -1;
}

/*
Data la seguente definizione:
Un libro L1 ha un riferimento ad un Libro L2 se:
- L1 ha un riferimento a L2, oppure
- L1 ha un riferimento a C3 e C3 ha un riferimento a C2.

Sia L il primo libro della biblioteca, il metodo deve restituire il numero di libri con cui L ha un riferimento.

Nel caso in cui non ci siano libri nella biblioteca restituisce -1.

*/
int Biblioteca::metodo4()
{
    /* IMPLEMENTARE QUESTO METODO */
    return -1;
}
