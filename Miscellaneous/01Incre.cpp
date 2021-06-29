#include <bits/stdc++.h>
using namespace std;

int main(){
    int a = 10;
    cout << ++a << endl;   //After this value will become 11 and get printed as well 11
    cout << a++ << endl;   //After this value will become 12 but it will get printed 11 only.

    cout << a-- << endl;   //After this value will become 11 but get printed as 12
    cout << --a << endl;   //After this value will become 10 and get printed 10

    return 0;
}