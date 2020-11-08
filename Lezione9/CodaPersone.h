#ifndef CODA_PERSONE_H
#define CODA_PERSONE_H

#include <list>
#include <iostream>
#include "Persona.h"
using namespace std;

class CodaPersone : protected list<Persona*> {
	public:
		bool empty() const;
		unsigned int size() const;
		Persona* front();
		Persona* back();
		void push(Persona* elem);
		void pop();
		void print() const;
};


#endif