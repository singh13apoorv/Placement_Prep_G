#include <bits/stdc++.h>
#include "03Constructor.cpp"
using namespace std;

int main(){
    Construct c1;
    c1.display();

    Construct c2(10);
    c2.display();

    Construct * c3 = new Construct(11, 21);
    c3->display();

    return 0;
}