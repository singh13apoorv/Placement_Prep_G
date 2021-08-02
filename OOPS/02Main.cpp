#include <bits/stdc++.h>
#include "02GetterAndSetter.cpp"
using namespace std;

int main(){
    Student s1;
    s1.rollNumber = 101;
    s1.setAge(21);
    s1.display();
    cout << s1.getAge() << endl;

    Student * s2 = new Student;
    s2->rollNumber = 102;
    s2->setAge(22);
    s2->display();
    cout << s2->getAge() << endl;

    return 0;
}