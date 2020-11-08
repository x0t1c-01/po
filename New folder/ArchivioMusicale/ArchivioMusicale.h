
#ifndef ArchivioMusicale_H
#define ArchivioMusicale_H

#include "Album.h"

#include <cstdlib>
#include <iostream>
#include <list>
#include <vector>

using namespace std;

/*

Questa classe contiene un archivio musicale di libri. Ogni album e` caratterizzato dalle seguenti informazioni:

    - titolo: il titolo dell'album (string);

    - autore: il nome dell'autore che ha scritto l'album (string);

    - prezzo: il prezzo dell'album (int);

    - tipo: il tipo dell'album (un enumerativo con 3 possibili valori: POP, ROCK, CLASSICA);

    - collegatoA: contiene musica di un altro album, stringa vuota se non esiste (string).
    
    Implementare nel file ArchivioMusicale.cpp i metodi della classe ArchivioMusicale.
    
*/
class ArchivioMusicale   // questa riga e` corretta NON MODIFICARE
{
private:
    list<Album> archivioMusicale;

public:
    // DESCRIZIONE NEL FILE .cpp
    int metodo1();

    // DESCRIZIONE NEL FILE .cpp
    int metodo2();

    // DESCRIZIONE NEL FILE .cpp
    int metodo3();

    // DESCRIZIONE NEL FILE .cpp
    int metodo4();

    
    
    inline bool aggiungi(Album l) {archivioMusicale.push_back(l); return true;}
    
    
    inline list<Album>& getContent() { return archivioMusicale; }
};
#endif
