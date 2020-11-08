#include <vector>
#include <iostream>
using namespace std;

void stampaVettore(vector<int>& v) {
    cout << "Vector:";
    for(int i = 0; i < v.size(); i++)
        cout << " " << v[i];
    cout << endl;
}

int main() {
    vector<int> v;
    v.push_back(3);
    v.push_back(1);
    v.push_back(2);
    
    stampaVettore(v);
    bool scambia = true;
    while(scambia) {
        scambia = false;
        for(int i = 0; i < v.size()-1; i++) {
            //Condizione di ordinamento:
            //Prima i dispari in ordine crescente, poi i pari in ordine crescente
            //Condizione implementata:
            //Scambia se -> il numero i-esimo è pari e il suo successivo è dispari oppure se sono entrambi pari (o entrambi dispari) e il numero i-esimo è maggiore del suo successivo        
            if( 
                (v[i]%2==0 &&v[i+1]%2!=0) // prima condizione: numero i-esimo pari e successivo dispari
                || (v[i]%2==v[i+1]%2 && v[i]>v[i+1]) //seconda condizione: entrambi pari (o entrambi dispari) e il numero i-esimo è maggiore del suo successivo
            )
            {
                int tmp = v[i];
                v[i] = v[i+1];
                v[i+1] = tmp;
                scambia = true;
            }
        }
    }
    stampaVettore(v);
}
