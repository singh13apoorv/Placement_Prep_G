#include <bits/stdc++.h>
#include "07OwnCopyConstructor.cpp"
using namespace std;

int main(){
    char name[] = "Apoorv";
    Student s1(21, name);
    s1.display();
    
    Student s2(s1);
    s2.name[0] = 'a';
    s2.display();
    s1.display();

    return 0;
}