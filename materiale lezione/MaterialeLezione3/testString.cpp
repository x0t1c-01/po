#include <string>
#include <iostream>
using namespace std;

int main() {
    string test = "ciao";
    test += "casa";
    char c = 'o';
    test += c;

    string sottostringa = test.substr(4,100);
    cout << "Stringa: " << test << endl;
    cout << "Sottostringa: " << sottostringa << endl;
}
