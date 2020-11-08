
#ifndef QuadruplaNumeri_H_
#define QuadruplaNumeri_H_

#include <iostream>
#include <string>

using namespace std;


    #include <algorithm>
    #include <cmath>
    #include <vector>
    

class QuadruplaNumeri
{
private:
    int num1;
    int num2;
    int num3;
    int num4;
    
public:
    QuadruplaNumeri(int _num1 = 0, int _num2 = 0, int _num3 = 0, int _num4 = 0) : num1(_num1), num2(_num2), num3(_num3), num4(_num4) {}

    int getNum1() const { return num1; }
    void setNum1(int v) { num1 = v; }

    int getNum2() const { return num2; }
    void setNum2(int v) { num2 = v; }



    int getNum3() const { return num3; }
    void setNum3(int v) { num3 = v; }

    int getNum4() const { return num4; }
    void setNum4(int v) { num4 = v; }

    

    bool operator==(const QuadruplaNumeri& right) const { return num1 == right.num1 && num2 == right.num2 && num3 == right.num3 && num4 == right.num4; }

friend ostream& operator<<(ostream& out, const QuadruplaNumeri& x) { return out << "[" << x.num1 << ", " << x.num2 << ", " << x.num3 << ", " << x.num4 << "]"; }
};

#endif
