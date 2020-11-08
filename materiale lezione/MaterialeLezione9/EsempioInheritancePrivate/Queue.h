#ifndef QUEUE_H
#define QUEUE_H

#include <list>
using namespace std;

template <class T>
class Queue : private list<T> {

    public:
        bool empty() const;
        unsigned int size() const;
        T front();
        T back();
        void push(T elem);
        void pop();
};

template <class T>
bool Queue<T>::empty() const {
    return list<T>::empty();
}

template <class T>
unsigned int Queue<T>::size() const {
    return list<T>::size();
}

template <class T>
T Queue<T>::front() {
    return list<T>::front();
}

template <class T>
T Queue<T>::back() {
    return list<T>::back();
}

template <class T>
void Queue<T>::push(T elem) {
    list<T>::push_back(elem);
}

template <class T>
void Queue<T>::pop() {
    list<T>::pop_front();
} 


#endif
