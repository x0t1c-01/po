#include "Pair.h"
#include <string>
#include <iostream>
using namespace std;

int main() {
    Pair<int,char> p1(1,'a');
    Pair<string, string> p2("ciao", "mondo");

    cout << p1.getSecond() << endl;
    cout << p2.getFirst() << endl;
}
