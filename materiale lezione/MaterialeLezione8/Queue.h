#ifndef QUEUE_H
#define QUEUE_H

#include <list>
using namespace std;

template <class T>
class Queue {

    public:
        bool empty() const;
        unsigned int size() const;
        T front();
        T back();
        void push(T elem);
        void pop();

    private:
        list<T> elements;
};

template <class T>
bool Queue<T>::empty() const {
    return elements.empty();
}

template <class T>
unsigned int Queue<T>::size() const {
    return elements.size();
}

template <class T>
T Queue<T>::front() {
    return elements.front();
}

template <class T>
T Queue<T>::back() {
    return elements.back();
}

template <class T>
void Queue<T>::push(T elem) {
    return elements.push_back(elem);
}

template <class T>
void Queue<T>::pop() {
    return elements.pop_front();
} 


#endif
