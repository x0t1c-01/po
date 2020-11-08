#ifndef LABORATORIO_H
#define LABORATORIO_H

#include <vector>
using namespace std;

#include "Paziente.h"

//La classe deve garantire il seguente ordine di priorità: prima tutti pazienti con un codice di priorità pari a 1 in ordine di numero; poi tutti i pazienti con un codice pari a 2 in ordine di età; infine tutti gli altri pazienti in ordine alfabetico di tipologia
bool precede(Paziente* p1, Paziente* p2) {
    if(p1->getCodice()==1 && p2->getCodice()!=1)
        return true;
    if(p2->getCodice()==1 && p1->getCodice()!=1)
        return false;
    if(p1->getCodice()==1 && p2->getCodice()==1)
        return p1->getNumero() < p2->getNumero();
    
    //Qui abbiamo gestito tutti i casi in cui uno dei due pazienti ha codice 1
    //Quindi p1->getCodice() e p2->getCodice() sono entrambi diversi da 1
    if(p1->getCodice()==2 && p2->getCodice()!=2)
        return true;
    if(p2->getCodice()==2 && p1->getCodice()!=2)
        return false;
    if(p1->getCodice()==2 && p2->getCodice()==2)
        return p1->getEta() < p2->getEta();

    //Qui abbiamo gestito tutti i casi in cui uno dei due pazienti ha codice 2
    //Quindi p1->getCodice() e p2->getCodice() sono entrambi diversi da 2
    return(p1->getTipologia() < p2->getTipologia());
}

bool nonprecede(Paziente* p1, Paziente* p2) {
    return !precede(p1,p2);
}

//Soluzione 1: i pazienti con priorità più alta sono messi all'inizio del vettore
/*class Laboratorio : private vector<Paziente*> {
    public:
        void add(Paziente* p) {
            for(auto it = begin(); it != end(); ++it)
                if(precede(p,*it)) {
                    insert(it, p);
                    return;
                }
            push_back(p);                  
        }
        
        Paziente* next() const { return front(); }
        void remove() { erase(begin()); }
        unsigned int size() const { return vector<Paziente*>::size(); }
};*/

//Soluzione 2: i pazienti con priorità più alta sono messi alla fine del vettore
class Laboratorio : private vector<Paziente*> {
    public:
        void add(Paziente* p) {
            for(auto it = begin(); it != end(); ++it)
                if(!precede(p,*it)) {
                    insert(it, p);
                    return;
                }
            push_back(p);                  
        }
        
        Paziente* next() const { return back(); }
        void remove() { pop_back(); }
        unsigned int size() const { return vector<Paziente*>::size(); }
};

//Soluzione 3: i pazienti con priorità più alta sono messi all'inizio del vettore (uso di sort)
/*class Laboratorio : private vector<Paziente*> {
    public:
        void add(Paziente* p) {
            push_back(p);
            sort(begin(), end(), precede);            
        }
        Paziente* next() const { return front(); }
        void remove() { erase(begin()); }
        unsigned int size() const { return vector<Paziente*>::size(); }
};*/

//Soluzione 4: i pazienti con priorità più alta sono messi alla fine del vettore (uso di sort)
/*class Laboratorio : private vector<Paziente*> {
    public:
        void add(Paziente* p) {
            push_back(p);
            sort(begin(), end(), nonprecede);            
        }
        Paziente* next() const { return back(); }
        void remove() { pop_back(); }
        unsigned int size() const { return vector<Paziente*>::size(); }
};*/

#endif