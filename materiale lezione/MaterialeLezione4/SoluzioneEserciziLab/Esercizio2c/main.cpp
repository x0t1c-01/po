#include <iostream>
#include <vector>
using namespace std;

void cerca(vector<char>& v, string parola) {
    string nuova = "";
    for(int i = 0; i < v.size(); i++)
        nuova += v[i];

    if(nuova.find(parola) != string::npos) {
        cout << "YES" << endl;
    }
    else {
        cout << "NO" << endl;
    }
}

int main() {
    vector<char> parola;
    char c;
    cin >> c;
    while(c != '0') {
        parola.push_back(c);
        cin >> c;
    }
    cerca(parola, "fondamenti");
    cerca(parola, "programmazione");
    cerca(parola, "oggetti");
}
