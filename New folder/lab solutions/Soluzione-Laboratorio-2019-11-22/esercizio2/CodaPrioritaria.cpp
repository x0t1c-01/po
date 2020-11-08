#include "CodaPrioritaria.h"
#include <cassert>

bool ordinamento(int n1, int n2) {
    if(n1 > 0 && n2 < 0)
        return true;
    if(n2 > 0 && n1 < 0)
        return false;
    if(n1 > 0 && n2 > 0) {
        if(n1 % 2 == 0 && n2 % 2 != 0)
            return true;
        if(n1 % 2 != 0 && n2 % 2 == 0)
            return false;
        return n1 < n2;
    }
    
    assert(n1 < 0 && n2 < 0);
    if(n1 % 2 != 0 && n2 % 2 == 0)
        return true;
    if(n1 % 2 == 0 && n2 % 2 != 0)
        return false;
    return -n1 < -n2;
}

void CodaPrioritaria::aggiungi(int n) {
    if(n != 0) {
        elementi.push_back(n);
        elementi.sort(ordinamento);
    }
}

int CodaPrioritaria::prossimoNumero() const {
    return elementi.front();
}

void CodaPrioritaria::rimuoviProssimoNumero() {
    return elementi.pop_front();
}

int CodaPrioritaria::size() const {
    return elementi.size();
}