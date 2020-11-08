#include <vector>
#include <iostream>
using namespace std;

void leggi(vector<char>& v) {
    char c;
    cin >> c;
    while (c != '0') {
         v.push_back(c);
         cin >> c;
    }
}

void stampa(vector<char>& v) {
    cout << "Vector:";
    for(int i = 0; i < v.size(); i++) {
        cout << " " << v[i];
    }
    cout << endl;
}

bool contiene(vector<char>& v, const string& parola) {
    if(v.size() < parola.length())
        return false;

    int j = 0;
    while(parola.length() + j <= v.size()) {
        bool trovato = false;
        for(int i = 0; i < parola.length(); i++) {
            if(parola[i] != v[j+i]) {
                trovato = true;
                j++;
                break;
            }
        }
        if(!trovato)
            return true;
    }
    return false;
}

bool numeri(vector<char>& v) {
    if(v.empty())
        return false;
    for(int i = 0; i < v.size(); i++) {
        if(v[i] < '0' || v[i] > '9')
            return false;
    }
    return true;
}

bool fortuna(vector<char>& v) {
    //La funzione è corretta perché fortuna non contiene ripetizioni!
    string f = "fortuna";
    for(int i = 0; i < f.length(); i++) {
        bool trovato = false;
        for(int j = 0; j < v.size(); j++) {
            if(f[i] == v[j]) {
                trovato = true;
                break;
            }
        }
        if(!trovato)
            return false;
    }
    return true;
}

void rimuoviVocali(vector<char>& v) {
    vector<char> tmp;
    for(int i = 0; i < v.size(); i++) {
        if(v[i] != 'a' && v[i] != 'e' && v[i] != 'i' && v[i] != 'o' && v[i] != 'u')
            tmp.push_back(v[i]);
    }
    v.swap(tmp);
}

int main() {
    vector<char> vettore;
    leggi(vettore);
    stampa(vettore);
    if(contiene(vettore, "fondamenti") || contiene(vettore, "programmazione") || contiene(vettore, "oggetti"))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    if(numeri(vettore))
        cout << "NUMERI" << endl;
    else
        cout << "ALTRO" << endl;

    if(fortuna(vettore))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    rimuoviVocali(vettore);
    stampa(vettore);

    return 0;
}
