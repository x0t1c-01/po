#include "Persona.h"

Persona::Persona(): codiceFiscale(""), nome(""), cognome("") {
}

Persona::Persona(const string& n, const string& c, const string& cf): codiceFiscale(cf), nome(n), cognome(c){
	
}

string Persona::getCodiceFiscale() const {
	return codiceFiscale;
}

string Persona::getNome() const {
	return nome;
}

string Persona::getCognome() const {
	return cognome;
}

void Persona::setCodiceFiscale(string s){
	codiceFiscale=s;
}

void Persona::setNome(string s){
	nome=s;
}

void Persona::setCognome(string s){
	cognome=s;
}

void Persona::stampa() const {
	cout<<nome<<" "<<cognome<<" "<<codiceFiscale;
}
