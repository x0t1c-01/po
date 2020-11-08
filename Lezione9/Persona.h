#ifndef PERSONA_H
#define PERSONA_H

#include <iostream>
using namespace std;

class Persona {
public:
	Persona();
	~Persona(); //Non e' necessario, serve per capire l'ordine di invocazione dei distruttori
	string getCodiceFiscale() const;
	string getNome() const;
	string getCognome() const;
	void setCodiceFiscale(string s);
	void setNome(string s);
	void setCognome(string s);
	virtual void stampa() const;
protected:
	string codiceFiscale;
	string nome;
	string cognome;
};

#endif