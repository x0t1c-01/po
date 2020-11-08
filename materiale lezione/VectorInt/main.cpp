#include <iostream>
using namespace std;

#include "VectorInt.h"

int main() {
    VectorInt v;
    for(int i = 0; i < 1000; i++)
        v.push_back(i);

    VectorInt v2;
    v2 = v;

    VectorInt v3(v);
    cout << "elemento:";
    for(int i = 0; i < v.size(); i++)
        cout << " " << v[i];
    cout << endl;

    for(int i = 0; i < v2.size(); i++)
        cout << " " << v2[i];
    cout << endl;
    v.resize(10);
    v[0] = 5;
    cout << "elemento:";
    for(int i = 0; i < v.size(); i++)
        cout << " " << v[i];
    cout << endl;
    for(int i = 0; i < v3.size(); i++)
        cout << " " << v3[i];
    cout << endl;
}
