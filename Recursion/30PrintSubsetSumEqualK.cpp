#include <bits/stdc++.h>

void printSubsetSumToK(int input[], int size, int startIdx, int k, int output[], int m){
    if (startIdx == size){
        if (k == 0){
            for (int i = 0; i < m; i++){
                cout << output[i] << " ";
            }
            cout << endl;
            return;
        }
        else {
            return;
        }
    }
    
    int otarr[m + 1];
    
    for (int i = 0; i < m; i++){
        otarr[i] = output[i];
    }
    otarr[m] = input[startIdx];
    
    printSubsetSumToK(input, size, startIdx + 1, k - input[startIdx], otarr, m + 1);
    printSubsetSumToK(input, size, startIdx + 1, k, output, m);
}



void printSubsetSumToK(int input[], int size, int k) {
    int output[size];
    // Write your code here
    printSubsetSumToK(input, size, 0, k, output, 0);
}

int main() {
    int input[1000],length,k;
    cin >> length;
    for(int i=0; i < length; i++)
        cin >> input[i];
    cin>>k;
    printSubsetSumToK(input, length,k);
}
