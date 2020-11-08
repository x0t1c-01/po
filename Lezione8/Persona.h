#ifndef PERSONA_H
#define PERSONA_H

#include <iostream>
using namespace std;

class Persona {
public:
	Persona();
	Persona(const string& n, const string& c, const string& cf);
	string getCodiceFiscale() const;
	string getNome() const;
	string getCognome() const;
	void setCodiceFiscale(string s);
	void setNome(string s);
	void setCognome(string s);
	void stampa() const;
protected:
	string codiceFiscale;
	string nome;
	string cognome;
};

#endif