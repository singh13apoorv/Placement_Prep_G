#include <bits/stdc++.h>
using namespace std;

bool isBalanced(string expression) 
{
    // Write your code here
    stack<char> s;
    
    for (int i = 0; i < expression.size(); i++){
        if (expression[i] == '('){
            s.push('(');
        }
        else if (expression[i] == ')'){
            if (s.empty()){
                return false;
            }
            s.pop();
        }
    }
    
    if (s.empty() != true){
        return false;
    }
    
    return true;
}

int main() 
{
    string input;
    cin >> input;
    cout << ((isBalanced(input)) ? "true" : "false");
}