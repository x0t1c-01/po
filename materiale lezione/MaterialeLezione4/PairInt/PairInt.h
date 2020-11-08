#ifndef PAIRINT_H
#define PAIRINT_H

class PairInt {

    public:
        PairInt(int f, int s);
        int getFirst() const;
        int getSecond() const;
        void setFirst(int f);
        void setSecond(int s);

    private:
        int first;
        int second;
};

#endif
