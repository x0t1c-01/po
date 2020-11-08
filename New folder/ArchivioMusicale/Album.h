
#ifndef Album_H_
#define Album_H_

#include <iostream>
#include <string>

using namespace std;


enum Tipo { POP = 0, ROCK, CLASSICA };
#include <algorithm>
#include <set>
    

class Album
{
private:
    string titolo;
    string autore;
    int prezzo;
    Tipo tipo;
    string collegamentoA;
    
public:
    Album(string _titolo = "", string _autore = "", int _prezzo = 0, Tipo _tipo = POP, string _collegamentoA = "") : titolo(_titolo), autore(_autore), prezzo(_prezzo), tipo(_tipo), collegamentoA(_collegamentoA) {}

    string getTitolo() const { return titolo; }
    void setTitolo(string v) { titolo = v; }

    string getAutore() const { return autore; }
    void setAutore(string v) { autore = v; }

    int getPrezzo() const { return prezzo; }
    void setPrezzo(int v) { prezzo = v; }

    Tipo getTipo() const { return tipo; }
    void setTipo(Tipo v) { tipo = v; }

    string getCollegamentoA() const { return collegamentoA; }
    void setCollegamentoA(string v) { collegamentoA = v; }

    

    bool operator==(const Album& right) const { return titolo == right.titolo && autore == right.autore && prezzo == right.prezzo && tipo == right.tipo && collegamentoA == right.collegamentoA; }

friend ostream& operator<<(ostream& out, const Album& x) { return out << "[" << x.titolo << ", " << x.autore << ", " << x.prezzo << ", " << x.tipo << ", " << x.collegamentoA << "]"; }
};

#endif
