#ifndef RUBRICA_H
#define RUBRICA_H

#include <string>
#include <vector>
using namespace std;

class Rubrica {

    public:
        void aggiungiNumero(string nome, string numero);
        string getNumero (string nome) const;
        void modificaNumero (string nome, string numero);
        void stampa() const;

    private:
        vector<string> nomi;
        vector<string> numeri;
};

#endif