#ifndef PRONTO_SOCCORSO_H
#define PRONTO_SOCCORSO_H

#include "Paziente.h"
#include <list>

class ProntoSoccorso : private list<Paziente> {
	public:
		unsigned int numeroPazientiInCoda();
		void aggiungiPaziente(const Paziente& p);
		void serviProssimoPaziente();
};

#endif