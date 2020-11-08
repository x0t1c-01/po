#ifndef VETTORI_H
#define VETTORI_H

#include <vector>
#include <string>
using namespace std;

class Vettori {

    public:
        void aggiungi(int n);
        void aggiungi(char c);
        void rimuoviMinori(int n);
        void rimuoviCarattere(char c);
        void genera();
        void stampa() const;

    private:
        vector<int> v1;
        vector<char> v2;
        vector<string> v3;
};

#endif
