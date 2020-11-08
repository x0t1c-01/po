#ifndef GESTORECONTATTO_H
#define GESTORECONTATTO_H

#include "Contatto.h"
#include <list>
#include <vector>
using namespace std;

class GestoreContatti{
	private:
		list<Contatto> contatti;
	public:
		GestoreContatti(){}
		void stampaContatti() const;
		bool inserisciContatto(const Contatto& c);
		bool eliminaContattoConRemove(const Contatto& c);
		bool eliminaContattoConErase(const Contatto& c);
		void ordina();
		string cognomePiuFrequente() const;
		vector<string> trovaNumeri(const string& nome, const string& cognome);
		bool verificaDueContattiStessoTelefono();
};

#endif








