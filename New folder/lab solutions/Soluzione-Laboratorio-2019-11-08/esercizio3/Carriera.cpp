#include "Carriera.h"

#include <iostream>
#include <climits>
using namespace std;

void Carriera::aggiungi(Esame* e) {
    if(e->getVoto() >= 18 && e->getVoto() <= 31)
        esami.push_back(e);
}

float Carriera::mediaVoti() const {
    float somma = 0.0;
    float crediti = 0.0;
    for(auto it = esami.begin(); it != esami.end(); ++it) {
        somma += (*it)->getVoto() * (*it)->getCrediti();
        crediti += (*it)->getCrediti();
    }
    if(crediti != 0.0)
        return somma/crediti;
    else
        return 0.0;
}

void Carriera::stampa() const {
    cout << "Carriera:" << endl;
    for(auto it = esami.begin(); it != esami.end(); ++it) {
        cout << **it << endl;
    }
}

void Carriera::stampa(string professore) const {
    cout << "Esami sostenuti con il professore " << professore << ":" << endl;
    for(auto it = esami.begin(); it != esami.end(); ++it) {
        if((*it)->getProfessore() == professore)
            cout << **it << endl;
    }
}

void Carriera::stampaEsamiMigliori() const {
    int max = INT_MIN;
    list<Esame*> esamiMigliori;
    for(auto it = esami.begin(); it != esami.end(); ++it) {
        if((*it)->getVoto() > max) {
            max = (*it)->getVoto();
            esamiMigliori.clear();            
        }
        if((*it)->getVoto() == max)
            esamiMigliori.push_back(*it);
    }
    cout << "Esami migliori:" << endl;
    for(auto it = esamiMigliori.begin(); it != esamiMigliori.end(); ++it) {
        cout << **it << endl;
    }
}

void Carriera::ordinaPerVoto() {
    bool scambia = true;
    while(scambia) {
        scambia = false;
        auto i = esami.begin();
        while(i != esami.end()) {
            auto j = i;
            ++i;
            if(i == esami.end())
                break;
            
            if((*j)->getVoto() < (*i)->getVoto()) {
                scambia = true;
                Esame* tmp = *j;
                *j = *i;
                *i = tmp;
            }
        }
    }
}

bool compare(const Esame* e1, const Esame* e2) {
    return e1->getNome() < e2->getNome();
}

void Carriera::ordinaPerNome() {
    esami.sort(compare);
}

bool Carriera::borsaDiStudio() const {    
    float media = mediaVoti();
    int crediti = 0;
    for(auto it = esami.begin(); it != esami.end(); ++it) {
        crediti += (*it)->getCrediti();
    }
    return media >= 25 && crediti >= 60;
}
