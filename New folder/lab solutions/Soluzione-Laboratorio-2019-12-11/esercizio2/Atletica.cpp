
#include "Atletica.h"

/*
Restituire l'atleta piu` pagato tra quelli che hanno partecipato ad almeno una gara di CENTO.

Lo stipendio di un atleta e` dato dalla somma dei premi ricevuti in tutte le gare vinte.
In caso di piu` atleti con lo stesso stipendio restituire il primo in ordine alfabetico.

Se non sono presenti atleti, restituire "-1".
Se nessun atleta ha partecipato ad una gara di CENTO, restituire "-2".
            
*/
int calcolaStipendio(string atleta, const list<Vincitore>& vincitori) {
    int stipendio = 0;
    for(auto v : vincitori)
        if(v.getAtleta() == atleta)
            stipendio += v.getPremio();
    return stipendio;
}

int calcolaStipendioDisciplina(string atleta, Disciplina d, const list<Vincitore>& vincitori) {
    int stipendio = 0;
    for(auto v : vincitori)
        if(v.getAtleta() == atleta && v.getDisciplina() == d)
            stipendio += v.getPremio();
    return stipendio;
}

list<string> getAtleti(const list<Vincitore>& vincitori) {
    list<string> a;
    for(auto v : vincitori)
        if(find(a.begin(), a.end(), v.getAtleta()) == a.end())
            a.push_back(v.getAtleta());
    return a;
}

string Atletica::metodo1()
{
    if(vincitori.empty())
        return "-1";
    
    int max = INT_MIN;
    string atleta = "-2";
    for(auto v : vincitori)
        if(v.getDisciplina() == CENTO) {
            int s = calcolaStipendio(v.getAtleta(), vincitori);
            if(s > max) {
                max = s;
                atleta = v.getAtleta();
            }
        }
    return atleta;
}

/*
Sia S1 lo stipendio dell'atleta con piu` vittorie nella STAFFETTA. (In caso di piu` atleti si consideri il primo in ordine di apparizione nella lista dei vincitori)
Sia S2 lo stipendio dell'atleta con meno vittorie nei CENTO. (In caso di piu` atleti si consideri il primo in ordine di apparizione nella lista dei vincitori)

Restituire S1-S2.

Se non sono presenti atleti, restituire -1.
            
*/
int Atletica::metodo2()
{
    if(vincitori.empty())
        return -1;
    
    int max = INT_MIN;
    string atletaMax;
    int min = INT_MAX;
    string atletaMin;
    
    list<string> atleti = getAtleti(vincitori);
    for(auto a : atleti) {
        int countStaffetta = 0;
        int countCento = 0;
        for(auto v : vincitori) {
            if(v.getAtleta() == a) {
                if(v.getDisciplina() == STAFFETTA)
                    countStaffetta++;
                else if(v.getDisciplina() == CENTO)
                    countCento++;
            }
        }
        if(countStaffetta > max) {
            max = countStaffetta;
            atletaMax = a;
        }
        if(countCento < min) {
            min = countCento;
            atletaMin = a;
        }
    }
        
    return calcolaStipendio(atletaMax, vincitori) - calcolaStipendio(atletaMin, vincitori);
}

/*
Creare una lista di atleti seguendo il seguente ordine:
1) stipendio (dal piu` basso al piu` alto)
2) ordine alfabetico.

Restituire il nome dell'atleta che si trova a meta` di questa lista (size/2).

Se non sono presenti atleti, restituire "-1".

ATTENZIONE: Non modificare la lista vincitori.
*/
            
string Atletica::metodo3()
{
    if(vincitori.empty())
        return "-1";
    
    list<string> atleti = getAtleti(vincitori);
    bool scambia = true;
    while(scambia) {
        scambia = false;
        for(auto it = atleti.begin(); it != atleti.end(); ++it) {
            auto it2 = it;
            advance(it2, 1);
            if(it2 == atleti.end())
                break;
            int s1 = calcolaStipendio(*it, vincitori);
            int s2 = calcolaStipendio(*it2, vincitori);
            if(s1 > s2 || (s1 == s2 && *it > *it2)) {
                string tmp = *it;
                *it = *it2;
                *it2 = tmp;
                scambia = true;
            }                        
        }
    }
    auto it = atleti.begin();
    advance(it, atleti.size()/2);
    return *it;
}

/* Soluzione alternativa al metodo 3

class Ordina {
    
    public:
        Ordina(list<Vincitore>& v) : vincitori(v) {}
        bool operator()(string a1, string a2) const {
            int s1 = calcolaStipendio(a1, vincitori);
            int s2 = calcolaStipendio(a2, vincitori);
            if(s1 < s2) return true;
            if(s1 == s2) return a1 < a2;
            return false;            
        }
    
    private:
        list<Vincitore> vincitori;
};

string Atletica::metodo3()
{
    if(vincitori.empty())
        return "-1";
    
    list<string> atleti = getAtleti(vincitori);
    atleti.sort(Ordina(vincitori));
    auto it = atleti.begin();
    advance(it, atleti.size()/2);
    return *it;
}
*/

/*
Sia A un atleta.
Sia C(A) la somma dei premi per vittorie di A nella categoria CENTO.
Sia D(A) la somma dei premi per vittorie di A nella categoria DUECENTO.
Sia S(A) la somma dei premi per vittorie di A nella categoria STAFFETTA.

Restituire il numero di atleti per cui C(A) + D(A) e` maggiore di S(A).
Se non sono presenti atleti, restituire -1.
            
*/
int Atletica::metodo4()
{
    if(vincitori.empty())
        return -1;

    int count = 0;    
    list<string> atleti = getAtleti(vincitori);
    for(auto a : atleti) {
        int c = calcolaStipendioDisciplina(a, CENTO, vincitori);
        int d = calcolaStipendioDisciplina(a, DUECENTO, vincitori);
        int s = calcolaStipendioDisciplina(a, STAFFETTA, vincitori);
        if(c+d > s)
            count++;
    }
    return count;
}


