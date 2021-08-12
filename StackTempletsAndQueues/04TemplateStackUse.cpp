#include <bits/stdc++.h>
#include "04StackUsingTemplate.cpp"
using namespace std;

int main(){
    Stack<char> s;

    s.pop();
    s.top();
    cout << s.isEmpty() << endl;

    s.push('A');
    s.push('P');
    s.push('O');
    s.push('O');
    s.push('R');
    s.push('V');

    s.top();
    s.pop();
    s.top();
    s.push(50);
    s.top();

    return 0;
}