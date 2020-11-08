#include "Gioielleria.h"

/*
    Un tipo T e` "prezioso" se il numero di gioielli d'oro di quel tipo 
    e` maggiore o uguale al numero di gioielli d'oro di ogni altro tipo.
    
    Un gioiello e` d'oro se come materiale ha ORO_BIANCO oppure ORO_GIALLO oppure ORO_ROSA.
    
    Restituire il primo tipo prezioso presente nella lista di gioielli 
    in base all'ordine di apparizione.
    
	Se non sono presenti gioielli o tipi preziosi, restituire ALTRO_TIPO.   
    
    Ad esempio, se la gioielleria contenesse i seguenti gioielli:
 
    ("O1", 150, OROLOGIO, ORO_BIANCO)
    ("A1", 800, ANELLO, ORO_BIANCO)
    ("A2", 600, ANELLO, ORO_GIALLO)
    ("C1", 300, COLLANA, ORO_ROSA)
    ("A3", 500, ANELLO, ARGENTO)
    ("OR1", 500, ORECCHINI, ORO_ROSA)
    ("O2", 200, OROLOGIO, ORO_ROSA)
 
    il metodo restituirebbe OROLOGIO. Infatti, avremmo:
    	OROLOGIO 	-> 2 gioielli d'oro
    	ANELLO 		-> 2 gioielli d'oro
    	COLLANA 	-> 1 gioiello d'oro
    	ORECCHINI 	-> 1 gioiello d'oro
    ed inoltre, tra OROLOGIO ed ANELLO nella lista compare prima OROLOGIO.
            
*/
list<Tipo> calcolaTipi(const list<Gioiello>& gioielli) {    
    list<Tipo> tipi;
    for(auto g : gioielli) {
        bool trovato = false;
        for(auto t : tipi) {
            if(g.getTipo() == t)
                trovato = true;            
        }
        if(!trovato)
            tipi.push_back(g.getTipo());            
    }
        
    return tipi;
}

Tipo Gioielleria::metodo1()
{
    int max = INT_MIN;
    Tipo tipoMax = ALTRO_TIPO;
    
    list<Tipo> tipi = calcolaTipi(gioielli);
        
    for(auto t : tipi) {
        int preziosi = 0;
        for(auto g : gioielli) {
            if(g.getTipo() != t)
                continue;
        
            auto mat = g.getMateriale();
            if(mat == ORO_BIANCO || mat == ORO_GIALLO || mat == ORO_ROSA)
                preziosi++;
        }
        if(preziosi > 0 && preziosi > max) {
            max = preziosi; 
            tipoMax = t;
        }
    }
    
    return tipoMax;
}

/*
    Un materiale M1 e` "economico" se esiste almeno un altro materiale M2 tale per cui 
    la cui media dei prezzi dei gioielli di materiale M2 e` strettamente maggiore 
    della media dei prezzi dei gioielli di materiale M1.
    
    Restituire il numero di materiali economici nella gioielleria.
    
	Se non sono presenti materiali economici, restituire 0.   
	Se non sono presenti gioielli, restituire -1.    
    
    Ad esempio, se la gioielleria contenesse i seguenti gioielli:
 
    ("O1", 150, OROLOGIO, ORO_BIANCO)
    ("A1", 800, ANELLO, ORO_BIANCO)
    ("A2", 600, ANELLO, ORO_GIALLO)
    ("C1", 300, COLLANA, ORO_ROSA)
    ("A3", 600, ANELLO, ARGENTO)
    ("OR1", 500, ORECCHINI, ORO_ROSA)
    ("O2", 200, OROLOGIO, ORO_ROSA)
 
    il metodo restituirebbe 2. I materiali economici sono ORO_BIANCO e ORO_ROSA.
    Infatti, avremmo come medie dei prezzi:
    	ORO_BIANCO 	-> 475
    	ORO_GIALLO 	-> 600
    	ORO_ROSA 	-> 333
    	ARGENTO 	-> 600
            
*/
int mediaPrezzi(Materiale materiale, list<Gioiello>& gioielli) {
    int count  = 0;
    int somma = 0;
    for(list<Gioiello>::iterator it2 = gioielli.begin(); it2 != gioielli.end(); it2++) {
        if(it2->getMateriale() != materiale) continue;
        count++;
        somma += it2->getPrezzo();
    }
    return somma/count;
}

vector<Materiale> calcolaMateriali(const list<Gioiello>& gioielli) {    
    vector<Materiale> materiali;
    for(auto g : gioielli) {
        //find ci permette di cercare all'interno di una lista o di un vector
        //se l'elemento c'è restituisce un iteratore
        //altrimenti restituisce end() della lista o del vector in cui stiamo facendo la ricerca
        if(find(materiali.begin(), materiali.end(), g.getMateriale()) == materiali.end())
            materiali.push_back(g.getMateriale());
    }        
    return materiali;
}

int Gioielleria::metodo2()
{
    if(gioielli.empty())
        return -1;
    
    vector<Materiale> materiali = calcolaMateriali(gioielli);
    int economici = 0;
    for(int i = 0; i < materiali.size(); i++) {
        for(int j = 0; j < materiali.size(); j++) {
                if(i == j) continue;
                if(mediaPrezzi(materiali[i], gioielli) < mediaPrezzi(materiali[j], gioielli)) {
                    economici++;
                    break;
                }
        }
    }
    
    return economici;
}

/*
	Sia T il tipo diverso da ALTRO_TIPO che abbia il minor numero di gioielli 
	ma tale per cui nella lista esista almeno un gioiello di tipo T.
	Nel caso in cui piu` tipi soddisfino tale proprieta`, si consideri come T 
	il primo tipo in ordine alfabetico presente nella lista.

	Restituire la descrizione del gioiello piu` costoso di tipo T.
	Nel caso in cui piu` gioielli soddisfino tale proprieta`, si consideri la descrizione 
	del primo gioiello in ordine di apparizione nella lista.

	Se non sono presenti gioielli, restituire "-1".
	Se non sono presenti gioielli con tipo diverso da ALTRO_TIPO, restituire "-2".

    Ad esempio, se la gioielleria contenesse i seguenti gioielli:
 
    ("O1", 150, OROLOGIO, ORO_BIANCO)
    ("A1", 800, ANELLO, ORO_BIANCO)
    ("A2", 600, ANELLO, ORO_GIALLO)
    ("C1", 300, COLLANA, ORO_ROSA)
    ("A3", 500, ANELLO, ARGENTO)
    ("OR1", 500, ORECCHINI, ORO_ROSA)
    ("O2", 50, OROLOGIO, ACCIAIO)
 
    il tipo T sarebbe COLLANA, pertanto il metodo restiruirebbe "C1".            
*/
int calcolaOccorrenze(Tipo t, list<Gioiello>& gioielli) {
    int occorrenze = 0;
    for(auto g : gioielli) {
        if(g.getTipo() == t)
            occorrenze++;
    }
    return occorrenze;
}

string Gioielleria::metodo3()
{
    if(gioielli.empty())
        return "-1";
    
    list<Tipo> tipi = calcolaTipi(gioielli);
    for(auto it = tipi.begin(); it != tipi.end(); ++it)
        if(*it == ALTRO_TIPO) {
            tipi.erase(it);
            break;
        }

    if(tipi.empty())
        return "-2";
    
    //Ordine alfabetico automatico per la scelta dei tipi
    tipi.sort();
    int min = INT_MAX;
    Tipo tMin = ALTRO_TIPO;
    for(auto t : tipi) {
        int o = calcolaOccorrenze(t, gioielli);
        if(o < min) {
            min = o;
            tMin = t;
        }
    }
    
    int max = INT_MIN;
    string descr = "-1";
    for(auto g : gioielli) {
        if(g.getTipo() == tMin && g.getPrezzo() > max) {
            max = g.getPrezzo();
            descr = g.getDescrizione();
        }
    }
    return descr;
}

/*
	Un materiale M e` predominante per un tipo T se tutti i gioielli di materiale M hanno tipo T.           
	Restituire il numero di materiali predominanti per almeno un tipo.

	Se non sono presenti gioielli, restituire -1.
	Se non sono presenti materiali che soddisfino tale proprieta`, restituire -2.

    Ad esempio, se la gioielleria contenesse i seguenti gioielli:
 
    ("B1", 400, BRACCIALE, ORO_BIANCO)
    ("A1", 800, ANELLO, ORO_BIANCO)
    ("C1", 300, COLLANA, ORO_ROSA)
    ("OR1", 500, ORECCHINI, ORO_ROSA)
    ("A2", 500, ANELLO, ARGENTO)
    ("A3", 50, ANELLO, ACCIAIO)
    ("B2", 100, BRACCIALE, ORO_GIALLO)
    ("B3", 100, BRACCIALE, ORO_GIALLO)
 
    il materiale ARGENTO sarebbe predominante per il tipo ANELLO,
    il materiale ACCIAIO sarebbe predominante per il tipo ANELLO.
    il materiale ORO_GIALLO sarebbe predominante per il tipo BRACCIALE.
    Pertanto il metodo restituirebbe 3.
            
*/
bool predominante(Materiale materiale, list<Gioiello>& gioielli) {
    bool first = true;
    Tipo t;
    for(auto g : gioielli) {
        if(g.getMateriale() == materiale) {
            if(first) {
                t = g.getTipo();
                first = false;
            }
            else if(t != g.getTipo()) //Se trovo un tipo diverso non è predominante
                return false;
        }
    }
    return true;
}

int Gioielleria::metodo4()
{
    if(gioielli.empty())
        return -1;
    
    vector<Materiale> materiali = calcolaMateriali(gioielli);    
    unsigned int predominanti = 0;
    for(int i = 0; i < materiali.size(); i++) {
        if(predominante(materiali[i], gioielli))
            predominanti++;
    }

    if(predominanti != 0)
        return predominanti;
    return -2;
}


