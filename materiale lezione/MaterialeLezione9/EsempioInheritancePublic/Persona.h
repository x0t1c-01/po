#ifndef PERSONA_H
#define PERSONA_H

#include <string>
using namespace std;

class Persona {

    public:
        Persona();
        Persona(string cf, string n, string c);
        
        void setCodiceFiscale(string cf);        
        void setNome(string n);
        void setCognome(string c);
        
        string getCodiceFiscale() const;
        string getNome() const;
        string getCognome() const;
        
    private:
        string codiceFiscale;
        string nome;
        string cognome;

};

#endif