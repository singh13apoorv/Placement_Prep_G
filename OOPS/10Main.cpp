#include <bits/stdc++.h>
#include "10OperatorOverloading.cpp"
using namespace std;

int main(){
    Fractions f1(10, 2);
    Fractions f2(15, 4);

    Fractions f3 = f1 * f2;
    Fractions f4 = f1 + f2;

    f1.print();
    f2.print();
    f3.print();
    f4.print();
    //++f1;
    //f1.print();
    f3 = ++f1;
    f1.print();
    f3.print();

    f4 = ++(++f1);
    f4.print();
    f1.print();

    Fractions f5 = f1 * f2;
    if (f5 == f1){
        cout << "equal" << endl;
    }
    else {
        cout << "not equal" << endl;
    }

    return 0;
}