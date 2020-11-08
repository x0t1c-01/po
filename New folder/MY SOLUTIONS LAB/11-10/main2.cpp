#include<iostream>
#include<vector>
using namespace std;

void leggi(vector<char>& v){
    char x;
    cin>>x;
    while(x!='0'){
        v.push_back(x);
        cin>>x;
    }
}

void stampa(vector<char>& v){
    for(int i=0;i<v.size();i++){
        cout<<v[i];
    }

}

bool contiene(vector<char>& v, const string& s){
    if(v.size()<s.length())
        return false;

    int j=0;
    while(s.length()+j<=v.size()){
        bool trovato=true;
        for(int i=0;i<s.length();i++){
            if(s[i]!=v[i+j]){
                trovato=false;
                j++;
                break;
            }
        }
        if(trovato)
            return true;
    }

    return false;
}

bool numeri(vector<char>& v){
    if(v.empty())
        return false;
    for(int i=0;i<v.size();i++){
        if(v[i]<0||v[i]>9)
            return false;
    }
    return true;
}

bool fortuna(vector<char>& v){
    string s="fortuna";

    for(int i=0;i<s.length();i++){
        bool trovato=false;
            for(int j=0;j<v.size();j++){
                if(s[i]==s[j])
                trovato=true;
                break;
            }
        if(!trovato)
            return false;
    }
    return true;
}

void rimuoviVocali(vector<char>& v){
    vector<char> tmp;
    for(int i=0;i<v.size();i++){
        if(v[i]!='a'&&v[i]!='e'&&v[i]!='i'&&v[i]!='o'&&v[i]!='u'){
            tmp.push_back(v[i]);
        }
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
