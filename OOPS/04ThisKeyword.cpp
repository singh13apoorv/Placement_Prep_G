#include <bits/stdc++.h>

class ThisKey{
    private:
    int rollNumber;
    int age;

    public:
    
    ThisKey(int rollNumber, int age){
        //this is a keyword which holds address of current object
        //this is a pointer
        this->rollNumber = rollNumber;
        this->age = age;
    }

    void display(){
        cout << rollNumber << " " << age << endl;
    }
};