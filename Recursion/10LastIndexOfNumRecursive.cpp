#include <bits/stdc++.h>
using namespace std;

int lastIndex(int input[], int size, int x) {
    if (size == 0){
        return -1;
    }
    int smallOutput = lastIndex(input + 1, size - 1, x);
    
    if (input[0] == x && smallOutput == -1){
        return 0;
    }
    
    if (smallOutput == -1){
        return -1;
    }
    else {
        return smallOutput + 1;
    }
}

int main(){
    int n;
    cin >> n;

    int *input = new int[n];
    
    for(int i = 0; i < n; i++) {
        cin >> input[i];
    }
    
    int x;
    
    cin >> x;
    
    cout << lastIndex(input, n, x) << endl;
}