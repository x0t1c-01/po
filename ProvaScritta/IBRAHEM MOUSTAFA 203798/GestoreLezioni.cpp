#include "GestoreLezioni.h"
#include <climits>

/*
* Restituisce la media dei distanziamenti tra tutte le lezioni presenti nella lista.
* Se non ci sono lezioni, restituisce -1.
*/
int GestoreLezioni::calcolaDistanziamentoMedio() const {
    if(lezioni.empty()){
        return -1;
    }
    int somma=0;
    for(auto it:lezioni){
        somma+=it.getPartecipanti();
    }

    return somma/lezioni.size();
}

/*
* Restituisce il distanziamento massimo tra tutte le lezioni di un docente passato come input.
* Se non ci sono lezioni del docente, restituisce -1.
*/
int GestoreLezioni::calcolaDistanziamentoMassimoDocente(string docente) const {
    if(lezioni.empty()){
        return -1;
    }
    int max=INT_MIN;
    for(auto it:lezioni){
        if(it.getDocente()==docente){
            if(max<it.getPartecipanti())
                max=it.getPartecipanti();
        }
    }
    return max;
}

/*
* Restituisce il distanziamento minimo tra tutte le lezioni di un'aula.
* Se non ci sono lezioni in un'aula, restituisce -1.
*/
int GestoreLezioni::calcolaDistanziamentoMinimoAula(string aula) const {
    if(lezioni.empty()){
        return -1;
    }
    int min=INT_MAX;
    for(auto it:lezioni){
        if(it.getAula()==aula){
            if(it.getPartecipanti<min)
                min=it.getPartecipanti();
        }
    }

    return min;
}
