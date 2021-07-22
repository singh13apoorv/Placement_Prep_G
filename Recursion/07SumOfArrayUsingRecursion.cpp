#include <bits/stdc++.h>
using namespace std;

int sum(int input[], int n) {
	if (n == 1){
        return input[n - 1];
    }
    
    int smallOutput = sum(input + 1, n - 1);
    int output = input[0] + smallOutput;
    
    return output;
}

int main(){
    int n;
    cin >> n;

    int *input = new int[n];
    
    for(int i = 0; i < n; i++) {
        cin >> input[i];
    }
    
    cout << sum(input, n) << endl;
}

