#ifndef Vector_String_H_
#define Vector_String_H_

#include <iostream>
using namespace std;


class VectorString
{
    public:
        VectorString();
        VectorString(const VectorString&);
        ~VectorString();

        unsigned int size() const;
        unsigned int capacity() const;

        void push_back(const string& e);
        void pop_back();

        VectorString& operator=(const VectorString& v);
		bool operator==(const VectorString& v);
		
		string operator[](unsigned int i) const;
        string& operator[](unsigned int i);

    private:
        string* vec;
        unsigned int sz;
        unsigned int cap;
};

#endif
