#include <bits/stdc++.h>
using namespace std;

class Student{
    public:
    int rollNumber;
    private:
    int age;

    public:
    void display(){
        cout << age << " " << rollNumber << endl;
    }
    //Getter function
    int getAge(){
        return age;
    }
    //Setter function
    void setAge(int a){
        age = a;
    }
};