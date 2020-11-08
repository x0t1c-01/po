#include "Queue.h"
#include "Stack.h"
#include <queue>
#include <stack>
#include <iostream>
using namespace std;

int main() {
    queue<int> queue;
    queue.push(1);
    queue.push(5);
    queue.push(7);
    queue.push(3);
    
    while(!queue.empty()) {
        cout << queue.front() << endl;
        queue.pop();
    }
    
    stack<int> stack;
    stack.push(1);
    stack.push(5);
    stack.push(7);
    stack.push(3);
    while(!stack.empty()) {
        cout << stack.top() << endl;
        stack.pop();        
    }
}




