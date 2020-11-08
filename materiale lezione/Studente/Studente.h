#ifndef STUDENTE_H
#define STUDENTE_H

#include <string>
using namespace std;

class Studente {

    public:
        Studente();
        Studente(unsigned int, unsigned int, string, string);

        unsigned int getMatricola() const;
        unsigned int getEta() const;
        string getNome() const;
        string getCognome() const;

        void setMatricola(unsigned int);
        void setEta(unsigned int);
        void setNome(string);
        void setCognome(string);

    private:
        unsigned int matricola;
        unsigned int eta;
        string nome;
        string cognome;
};

#endif
