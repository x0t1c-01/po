#include <vector>
#include <iostream>
using namespace std;

void leggi(vector<int>& v) {
    int num;
    cin >> num;
    while (num != -1) {
         v.push_back(num);
         cin >> num;
    }
}

void stampa(vector<int>& v, int size) {
    if(size > v.size())
        return;
    cout << "Vector:";
    for(int i = 0; i < size; i++) {
        cout << " " << v[i];
    }
    cout << endl;
}

void ordina(vector<int>& v) {
    bool scambio = true;
    while(scambio) {
        scambio = false;
        for(int i = 0; i < v.size()-1; i++) {
            if((v[i] % 2 == 0 && v[i+1] % 2 != 0) || (v[i]%2 == v[i+1]%2) && v[i] > v[i+1]){
                int tmp = v[i];
                v[i] = v[i+1];
                v[i+1] = tmp;
                scambio = true;
            }
        }
    }
}

int main() {
    vector<int> vettore;
    leggi(vettore);
    stampa(vettore, vettore.size());
    int n;
    cout << "Inserisci n: ";
    cin >> n;
    stampa(vettore, n);
    ordina(vettore);
    stampa(vettore, vettore.size());
    vettore.clear();
    return 0;
}
