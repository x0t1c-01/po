#include "Mondiale.h"

#include <climits>
#include <cmath>

int Mondiale::metodo1()
{
    if(partite.empty())
        return -1;
    
    int media = 0;                
    for(auto p : partite) {
        media += (p.getGolSquadra1()+p.getGolSquadra2());
    }
    media=media/partite.size();
    
    int min=INT_MAX;
    for(auto p : partite) {
        unsigned int golPartita = p.getGolSquadra1() + p.getGolSquadra2();
        if(golPartita >= media && golPartita < min) {
            min = golPartita;
        }
    }
    return min;
}

list<string> getArbitri(const list<Partita>& partite) {
    list<string> arbitri;
    
    for(auto p : partite) {
        string arbitro = p.getArbitro();
        bool trovato = false;
        for(auto a : arbitri) {
            if(a == arbitro) {
                trovato = true;
                break;
            }            
        }
        if(!trovato)
            arbitri.push_back(arbitro);
    }
    return arbitri;
}

bool esisteSquadra(const list<string>& squadre, string squadra) {
    for(auto s : squadre) {
        if(s == squadra) {
            return true;
        }            
    }
    return false;
}

list<string> getSquadre(const list<Partita>& partite) {
    list<string> squadre;
    
    for(auto p : partite) {
        if(!esisteSquadra(squadre, p.getSquadra1()))
            squadre.push_back(p.getSquadra1());
        if(!esisteSquadra(squadre, p.getSquadra2()))
            squadre.push_back(p.getSquadra2());    
    }
    return squadre;
}

int Mondiale::metodo2()
{
    if(partite.empty())
        return -1;

    list<string> arbitri = getArbitri(partite);
    list<string> squadre = getSquadre(partite);
    
    unsigned int count = 0;
    for(auto a : arbitri) {
        bool ok = true;
        for(auto s : squadre) {
            unsigned int conta = 0;
            for(auto p : partite) {
                if(p.getArbitro() == a && (p.getSquadra1() == s || p.getSquadra2() == s))
                    conta++;
            }
            if(conta > 1)
                ok = false;
        }

        if(ok)
            count++;
    }

    return count;
}

int Mondiale::metodo3()
{
    if(partite.empty())
        return -1;

    list<string> arbitri = getArbitri(partite);
    
    unsigned int count = 0;
    for(auto a : arbitri) {
        bool ok = true;
        for(auto p : partite) {
            if(p.getArbitro() == a && (abs(p.getGolSquadra1()-p.getGolSquadra2()) <= 2))
                ok = false;            
        }

        if(ok)
            count++;
    }

    return count;
}

bool domina(const Partita& p) {
    return (p.getGolSquadra2() >= (p.getGolSquadra1()+2));
}

bool in(string elem, const vector<string>& v) {
    for(auto e : v)
        if(e == elem)
            return true;
    return false;
}

int Mondiale::metodo4()
{
    if( partite.empty() )
        return -1;

    vector<string> daVisitare;
    vector<string> visitati;

    daVisitare.push_back(partite.front().getSquadra1());

    while(!daVisitare.empty()) {
        string corrente = daVisitare.back();
        daVisitare.pop_back();
        visitati.push_back(corrente);
        
        for(auto p : partite) {
            if(p.getSquadra2()==corrente && domina(p) && !in(p.getSquadra1(), visitati) && !in(p.getSquadra1(), daVisitare))
                daVisitare.push_back(p.getSquadra1());
        }
    }
    return visitati.size(); 
}