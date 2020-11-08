#ifndef VETTORI_H_
#define VETTORI_H_
#include<vector>

class Vettori(){

private:
    vector<int> v1;
    vector<char> v2;
    vector<string> v3;

public:

    void aggiungi(int n);
    void aggiungi(char c);
    void rimuoviMinori(int n);
    void rimuoviCarattere(char c);
    void genera();
    void stampa() const;


};














#endif
