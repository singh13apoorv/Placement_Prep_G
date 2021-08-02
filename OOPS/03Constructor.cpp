#include <bits/stdc++.h>
using namespace std;

class Construct{
    private:
    int rollNumber;
    int age;

    public:

    Construct(){
        cout << "Default constructor called !" << endl;
    }

    Construct(int r){
        cout << "Parameterised constructor 1 caller !" << endl;
        rollNumber = r;
    }

    Construct(int r, int a){
        cout << "Parameterised constructor 2 called !" << endl;
        rollNumber = r;
        age = a;
    }

    void display(){
        cout << rollNumber << " " << age << endl;
    }
};