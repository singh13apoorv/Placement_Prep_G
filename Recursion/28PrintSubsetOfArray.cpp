#include <bits/stdc++.h>

void ArraySubset(int input[], int size, int output[], int m){
    if (size == 0){
        for (int i = 0; i < m; i++){
            cout << output[i] << " ";
        }
        cout << endl;
        return;
    }
    
    int newArr[m + 1];
    
    for (int i = 0; i < m; i++){
        newArr[i] = output[i];
    }
    newArr[m] = input[0];
    
    ArraySubset(input + 1, size - 1, newArr, m + 1);
    ArraySubset(input + 1, size - 1, output, m);
}


void printSubsetsOfArray(int input[], int size) {
	// Write your code here
    int output[size];
    
    ArraySubset(input, size, output, 0);
}

int main() {
    int input[1000],length;
    cin >> length;
    for(int i=0; i < length; i++)
        cin >> input[i];
    printSubsetsOfArray(input, length);
}