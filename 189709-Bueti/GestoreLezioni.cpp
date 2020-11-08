#include "GestoreLezioni.h"
#include <climits>
#include <vector>

//  189709 - Bueti Giovanni Serafino

/*
* Restituisce la media dei distanziamenti tra tutte le lezioni presenti nella lista.
* Se non ci sono lezioni, restituisce -1.
*/
int GestoreLezioni::calcolaDistanziamentoMedio() const {
    if (lezioni.empty()) return -1;
    
    int sum = 0;
    for (auto p: lezioni)
        sum += p->calcolaDistanziamento();

    return sum / lezioni.size();
}

/*
* Restituisce il distanziamento massimo tra tutte le lezioni di un docente passato come input.
* Se non ci sono lezioni del docente, restituisce -1.
*/
int GestoreLezioni::calcolaDistanziamentoMassimoDocente(string docente) const {
    vector<Lezione*> _lezioni;

    for (auto p: lezioni) 
        if (p->getDocente() == docente)
            _lezioni.push_back(p);

    if (_lezioni.empty())
        return -1;

    int max = 0;
    for (auto p: _lezioni) 
        if (p->calcolaDistanziamento() > max)
            max = p->calcolaDistanziamento();

    return max;
}

/*
* Restituisce il distanziamento minimo tra tutte le lezioni di un'aula.
* Se non ci sono lezioni in un'aula, restituisce -1.
*/
int GestoreLezioni::calcolaDistanziamentoMinimoAula(string aula) const {
    vector<Lezione*> _lezioni;

    for (auto p: lezioni) 
        if (p->getAula() == aula)
            _lezioni.push_back(p);

    if (_lezioni.empty())
        return -1;

    int min = INT_MAX;
    for (auto p: _lezioni) 
        if (p->calcolaDistanziamento() < min)
            min = p->calcolaDistanziamento();

    return min;
}