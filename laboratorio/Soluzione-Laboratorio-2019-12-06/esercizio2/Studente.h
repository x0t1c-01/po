#ifndef STUDENTE_H
#define STUDENTE_H

#include <string>
#include <iostream>
using namespace std;

class Studente {
    
    public:
        Studente(unsigned int m, float i, float me) : matricola(m), isee(i), media(me) {}
        
        unsigned int getMatricola() const { return matricola; }
        float getIsee() const { return isee; }
        float getMedia() const { return media; }
    
    
        friend ostream& operator<<(ostream& o, const Studente& s) {
            o << s.matricola << " " << s.isee << " " << s.media;
            return o;
        }
    private:
        unsigned int matricola;
        float isee;
        float media;
};

#endif