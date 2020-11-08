#ifndef STUDENTE_H
#define STUDENTE_H

#include "Persona.h"

class Studente : public Persona {
public:
	Studente();
	~Studente(); //Non e' necessario, serve per capire l'ordine di invocazione dei distruttori
	float getIsee() const;
	void setIsee(float);
	virtual void stampa() const override;
private:
	float isee;
};


#endif