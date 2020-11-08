#ifndef	STUDENTE_H
#define STUDENTE_H

#include"persona.h"

class Studente : public Persona{

public:
	Studente();
	Studente(string cf, float is);
	
	float getIsee()const;
	void setIsee(float);



private:
	float isee;
};


#endif