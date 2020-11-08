#ifndef LEZIONE_H
#define LEZIONE_H

#include <string>
using namespace std;

class Lezione {
    
    public:
        virtual ~Lezione() {}
        Lezione(string d, string a, int p) : docente(d), aula(a), partecipanti(p) {}
        string getDocente() const { return docente; }
        string getAula() const { return aula; }
        int getPartecipanti() const { return partecipanti; }
        virtual int calcolaDistanziamento() const = 0;        
        
    private:
        string docente;
        string aula;
        int partecipanti;        
};

#endif