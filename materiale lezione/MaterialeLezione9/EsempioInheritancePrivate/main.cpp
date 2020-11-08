#include "Queue.h"
#include <iostream>
using namespace std;

int main() {
    Queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    
    while(!q.empty()) {
        cout << q.front() << endl;
        q.pop();
    }
    cout << q.size() << endl;    
    

    return 0;
}