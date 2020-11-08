#ifndef PROFESSORE_H
#define PROFESSORE_H

#include"persona.h"

class Professore : public Persona {

public:
	Professore();
	Professore(string cf, float is);

	float getStipendio()const;
	void setStipendio(float);

private:
	float stipendio;
};

#endif
