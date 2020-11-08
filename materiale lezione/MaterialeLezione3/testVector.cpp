#include <vector>
#include <climits>
#include <iostream>
#include <cassert>
using namespace std;

/*
restituisce il numero che occorre più spesso in v, in caso di parità, restituisce il primo.
Si può assumere che v contenga almeno un elemento.
*/

int frequente(vector<int>& v) {
    assert(!v.empty());
    int max = INT_MIN;
    int numMax = 0;
    for(int i = 0; i < v.size(); i++) {
        int cont = 0;
        for(int j = 0; j < v.size(); j++) {
            if(v[i] == v[j])
                cont++;
        }
        if(cont > max) {
            max = cont;
            numMax = v[i];
        }
    }
    return numMax;
}

int main() {
    vector<int> v;
    v.push_back(1);
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    cout << frequente(v) << endl;
}
