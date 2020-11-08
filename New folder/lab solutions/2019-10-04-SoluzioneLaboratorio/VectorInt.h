#ifndef VECTORINT_H_
#define VECTORINT_H_

#include <iostream>
using namespace std;

class VectorInt
{
    public:
        VectorInt();
        VectorInt(const VectorInt&);
        ~VectorInt();

        unsigned int size() const;
        unsigned int capacity() const;

        void push_back(int e);
        void pop_back();
        void reserve(unsigned int size);
        void resize(unsigned int size);
        int operator[](unsigned int i) const;
        int& operator[](unsigned int i);

        VectorInt& operator=(const VectorInt& v);

    private:
        int* vec;
        unsigned int sz;
        unsigned int cap;
};

#endif
