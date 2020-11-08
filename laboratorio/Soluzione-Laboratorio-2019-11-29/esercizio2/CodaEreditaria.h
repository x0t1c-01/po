#ifndef CODA_EREDITARIA_H
#define CODA_EREDITARIA_H

#include <list>
#include <vector>
using namespace std;

class CodaEreditaria : private list<char> {
    public:
        void aggiungi(char n);
        char prossimo() const;
        void rimuovi();
        int size() const;
        
    private:
        vector<char> accepted = {'b', 'c', 'd', 'f', 'g', 'h', 'l', 'm', 'n', 'p', 'q', 'r', 's', 't', 'v', 'z'};
    
};

#endif