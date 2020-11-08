#include "CodaEreditaria.h"
#include <cassert>

void CodaEreditaria::aggiungi(char c) {
    if(find(accepted.begin(), accepted.end(), c) == accepted.end())
        return;
    
    if(c == 'p') {
        push_front(c);
        return;
    }
    if(c == 'g') {
        for(auto i = begin(); i != end(); ++i)
            if(*i == 't') {
                insert(i, c);
                return;
            }
    }
        
    push_back(c);    
}

char CodaEreditaria::prossimo() const {
    return front();
}

void CodaEreditaria::rimuovi() {
    return pop_front();
}

int CodaEreditaria::size() const {
    return list<char>::size();
}