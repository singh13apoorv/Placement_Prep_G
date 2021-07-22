#include <bits/stdc++.h>
using namespace std;

int allIndexes(int input[], int size, int x, int output[]) {
	if (size == 0){
        return 0;
    }
    int smallOutput = allIndexes(input + 1, size - 1, x, output);
    
    if (input[0] == x){
        for (int i = smallOutput - 1; i >= 0; i--) {
            output[i + 1] = output[i] + 1;
        }
        // Put the start index in front
        // of the array
        output[0] = 0;
        smallOutput++;
    }
    else {
        for (int i = smallOutput - 1; i >= 0; i--) {
            output[i] = output[i] + 1;
        }
    }
    return smallOutput;
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
    
    int *output = new int[n];
    
    int size = allIndexes(input, n, x, output);
    for(int i = 0; i < size; i++) {
        cout << output[i] << " ";
    }
    
    delete [] input;
    delete [] output;
}