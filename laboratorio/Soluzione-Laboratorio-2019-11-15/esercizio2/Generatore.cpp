#include "Generatore.h"

#include <climits>
#include <vector>
using namespace std;

int Generatore::generaNumero() {
    int r;
    bool check = false;
    if(numeri.size() == 20010) {
        return INT_MAX;
    }    
    do
    {
        r = (rand() % 2001) - 1000;
        int count = 0;
        for(auto elem : numeri)
            if(elem == r)
                count++;
        if(count < 10)
            check = true;            
    } while(!check);
    numeri.push_back(r);
    return r;    
}

int Generatore::numeroFrequente() const {
    int max = INT_MIN;
    int nmax = INT_MIN;
    for(auto elem : numeri) {
        int count = 0;
        for(auto elem2 : numeri) {
            if(elem == elem2)
                count++;
        }
        if(count > max) {
            max = count;
            nmax = elem;
        }
    }     
    return nmax;   
}

bool primo(int n) {
    if(n <= 1)
        return false;
    for(int i = 2; i < n; i++)
        if(n % i == 0)
            return false;
    return true;
}

int Generatore::generaNumeroPrimo () const {
    int r = rand() % 10001;
    
    while(!primo(r))
        r = rand() % 10001;
    return r;    
}

void Generatore::cancellaNumero(int num, int n) {
    if(n <= 0)
        return;
    int countEliminati = 0;
    for(auto it = numeri.begin(); it != numeri.end(); ) {
        if(*it == num) {
            it = numeri.erase(it);
            countEliminati++;
            if(countEliminati==n)
                return;
        }
        else {
            ++it;
        }
    }
}