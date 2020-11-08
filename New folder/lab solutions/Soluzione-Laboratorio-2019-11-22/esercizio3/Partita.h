#ifndef Partita_H_
#define Partita_H_

#include <iostream>
#include <string>
using namespace std;
    
class Partita
{
    private:
        string squadra1;
        string squadra2;
        int golSquadra1;
        int golSquadra2;
        string arbitro;
        
    public:
        Partita(string _squadra1 = "", string _squadra2 = "", int _golSquadra1 = 0, int _golSquadra2 = 0, string _arbitro = "") : squadra1(_squadra1), squadra2(_squadra2), golSquadra1(_golSquadra1), golSquadra2(_golSquadra2), arbitro(_arbitro) {}
    
        string getSquadra1() const { return squadra1; }
        void setSquadra1(string v) { squadra1 = v; }
    
        string getSquadra2() const { return squadra2; }
        void setSquadra2(string v) { squadra2 = v; }
    
        int getGolSquadra1() const { return golSquadra1; }
        void setGolSquadra1(int v) { golSquadra1 = v; }
    
        int getGolSquadra2() const { return golSquadra2; }
        void setGolSquadra2(int v) { golSquadra2 = v; }
    
        string getArbitro() const { return arbitro; }
        void setArbitro(string v) { arbitro = v; }
    
        
    
        bool operator==(const Partita& right) const { return squadra1 == right.squadra1 && squadra2 == right.squadra2 && golSquadra1 == right.golSquadra1 && golSquadra2 == right.golSquadra2 && arbitro == right.arbitro; }
    
    friend ostream& operator<<(ostream& out, const Partita& x) { return out << "[" << x.squadra1 << ", " << x.squadra2 << ", " << x.golSquadra1 << ", " << x.golSquadra2 << ", " << x.arbitro << "]"; }
};

#endif
