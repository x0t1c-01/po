#include "CodaEreditaria.h"
#include <cassert>

void CodaEreditaria::aggiungi(Studente studente) {
    for(auto s : *this) {
        if(s.getMatricola() == studente.getMatricola())
            return;
    }
    
    for(auto it = begin(); it != end(); ++it) {
        if(studente.getMedia() > 28.0) {
            if(it->getMedia() <= 28.0) {
                insert(it, studente);
                return;
            }                   
        } else if(studente.getMedia() >= 26.0) {
            if(it->getMedia() < 26.0) {
                insert(it, studente);
                return;
            }
            else if(it->getMedia() >= 26.0 && it->getMedia() <= 28.0)
                if(studente.getMatricola() < it->getMatricola()) {
                    insert(it, studente);
                    return;
                }                    
        } else {
            if(it->getMedia() < 26.0)
                if(studente.getIsee() < it->getIsee()) {
                    insert(it, studente);
                    return;
                }                    
        }
    }            
    push_back(studente);    
}

Studente CodaEreditaria::prossimo() const {
    return front();
}

void CodaEreditaria::rimuovi() {
    pop_front();
}

unsigned int CodaEreditaria::size() const {
    return list<Studente>::size();
}