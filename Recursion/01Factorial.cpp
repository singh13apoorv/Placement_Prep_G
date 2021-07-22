#include <bits/stdc++.h>
using namespace std;

int Factorial(int n){
    if (n == 0){
        return 1;
    }
    int smallOutput = Factorial(n - 1);
    return n * smallOutput;
}

int main(){
    int n;
    cin >> n;

    cout << Factorial(n) << endl;
    return 0;
}