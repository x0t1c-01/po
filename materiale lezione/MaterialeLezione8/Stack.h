#ifndef STACK_H
#define STACK_H

#include <vector>
using namespace std;

template <class T>
class Stack {

    public:
        bool empty() const;
        unsigned int size() const;
        T top();
        void push(T elem);
        void pop();

    private:
        vector<T> elements;
};

template <class T>
bool Stack<T>::empty() const {
    return elements.empty();
}

template <class T>
unsigned int Stack<T>::size() const {
    return elements.size();
}

template <class T>
T Stack<T>::top() {
    return elements.back();
}

template <class T>
void Stack<T>::push(T elem) {
    return elements.push_back(elem);
}

template <class T>
void Stack<T>::pop() {
    return elements.pop_back();
} 


#endif
