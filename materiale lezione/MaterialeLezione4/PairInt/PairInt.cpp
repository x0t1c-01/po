#include "PairInt.h"

PairInt::PairInt(int f, int s) {
    first = f;
    second = s;
}

int PairInt::getFirst() const {
    return first;
}

int PairInt::getSecond() const {
    return second;
}

void PairInt::setFirst(int f) {
    first = f;
}

void PairInt::setSecond(int s) {
    second = s;
}
