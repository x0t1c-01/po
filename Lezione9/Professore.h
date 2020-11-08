#ifndef PROFESSORE_H
#define PROFESSORE_H

#include "Persona.h"

class Professore : public Persona {
public:
	Professore();
	~Professore();
	float getStipendio() const;
	void setStipendio(float);
	virtual void stampa() const override;
private:
	float stipendio;
};



#endif