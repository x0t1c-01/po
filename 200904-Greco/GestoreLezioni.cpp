#include "GestoreLezioni.h"
#include <climits>

/*
* Restituisce la media dei distanziamenti tra tutte le lezioni presenti nella lista.
* Se non ci sono lezioni, restituisce -1.
*/
int GestoreLezioni::calcolaDistanziamentoMedio() const {
  if(!lezioni.empty()){
    int distanziamento = -1;
    for(auto l:lezioni){
      distanziamento += l->calcolaDistanziamento();
    }
    return distanziamento/lezioni.size();
  }
  return -1;
}

/*
* Restituisce il distanziamento massimo tra tutte le lezioni di un docente passato come input.
* Se non ci sono lezioni del docente, restituisce -1.
*/
int GestoreLezioni::calcolaDistanziamentoMassimoDocente(string docente) const {
    int toReturn = -1;
    for(auto l:lezioni)
      if(l->getDocente() == docente)
        if(l->calcolaDistanziamento() > toReturn)
          toReturn = l->calcolaDistanziamento();
    return toReturn;
}

/*
* Restituisce il distanziamento minimo tra tutte le lezioni di un'aula.
* Se non ci sono lezioni in un'aula, restituisce -1.
*/
int GestoreLezioni::calcolaDistanziamentoMinimoAula(string aula) const {
  int toReturn = -1;
  for(auto l:lezioni)
    if(l->getAula() == aula)
      if(l->calcolaDistanziamento() < toReturn)
        toReturn = l->calcolaDistanziamento();
  return toReturn;
}
