#include "List.h"

#include <iostream>
#include <list>
using namespace std;

int main() {
    //Nostra implementazione
    List<int> l;
    l.push_back(1);
    l.push_front(2);
    l.push_back(3);
    l.push_front(4);
    
    cout << "Lista:";
    for(List<int>::Iterator it = l.begin(); it != l.end(); it++) {        
        cout << " " << *it;
    }
    cout << endl;
    
    cout << "Uso di auto:";
    for(auto it = l.begin(); it != l.end(); it++) {        
        cout << " " << *it;
    }
    cout << endl;
    
    cout << "Uso del foreach:";
    //for(int& elem : l) se vogliamo modificare l'elemento
    for(int elem : l) {
        cout << " " << elem;
    }
    cout << endl;
    
    cout << "Uso del foreach e auto:";
    //for(auto& elem : l) se vogliamo modificare l'elemento
    for(auto elem : l) {
        cout << " " << elem;
    }
    cout << endl;
    
    //list si usa allo stesso modo della nostra classe.    
    list<int> l1;
    l1.push_back(1);
    l1.push_front(2);
    l1.push_back(3);
    l1.push_front(4);
}