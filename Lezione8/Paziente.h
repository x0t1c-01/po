#ifndef PAZIENTE_H_
#define PAZIENTE_H_
	
#include "Persona.h"

enum CodiceUrgenza {
	BIANCO = 0, VERDE, GIALLO, ROSSO
};

class Paziente : public Persona {
	private:
		CodiceUrgenza codice;
	public:
		Paziente();
		Paziente(const string& n, CodiceUrgenza c);
		Paziente(const string& n, const string& c, const string& cf, CodiceUrgenza co);
		CodiceUrgenza getCodice() const;
		void setCodice(CodiceUrgenza codice);
		void stampa() const;
		bool operator<=(const Paziente& p) const;
};
#endif