#ifndef PAIR_H
#define PAIR_H

template<class T>
class Pair {

    public:
        Pair(T f, T s);
        T getFirst() const;
        T getSecond() const;
        void setFirst(T f);
        void setSecond(T s);

    private:
        T first;
        T second;
};

template<class T>
Pair<T>::Pair(T f, T s) {
    first = f;
    second = s;
}

template<class T>
T Pair<T>::getFirst() const {
    return first;
}

template<class T>
T Pair<T>::getSecond() const {
    return second;
}

template<class T>
void Pair<T>::setFirst(T f) {
    first = f;
}

template<class T>
void Pair<T>::setSecond(T s) {
    second = s;
}

#endif
