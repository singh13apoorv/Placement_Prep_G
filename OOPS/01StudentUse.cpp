#include <bits/stdc++.h>
#include "01Student.cpp"
using namespace std;

int main(){
    Student s1;  //creates object statically

    //Accessing and inputing the values to the objects property
    s1.age = 24;
    s1.rollNumber = 101;

    //Printing the object properties
    cout << s1.age << " " << s1.rollNumber << endl;

    Student * s2 = new Student;  //creates object dynamically

    //Accessing and inputing the values to the objects property in dynamically created variables
    (*s2).age = 23;
    (*s2).rollNumber = 102;

    //printing the object's properties
    cout << (*s2).age << " " << (*s2).rollNumber << endl;

    //or we can write
    s2 -> age = 22;
    s2 -> rollNumber = 103;

    //printing the object's properties
    cout << s2->age << " " << s2->rollNumber << endl;

    delete s2;
}