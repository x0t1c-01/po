#ifndef ESAME_H
#define ESAME_H

#include <string>
#include <iostream>
using namespace std;

class Esame {

    public:
        Esame(string n, string p, int v, int c);
        string getNome() const;
        string getProfessore() const;
        int getVoto() const;
        int getCrediti() const;
        friend ostream& operator<<(ostream& o, const Esame& e) {
            o << e.nome << ": " << e.voto << " - " << e.crediti << " - " << e.professore;
            return o;
        } 

    private:
        string nome;
        string professore;
        int voto;
        int crediti;    
};

#endif