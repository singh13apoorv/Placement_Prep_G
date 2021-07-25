#include <bits/stdc++.h>
using namespace std;

int subseq(string input, string output[]){
    if (input.empty()){
        output[0] = "";
        return 1;
    }

    string smallString = input.substr(1);
    int smallAnsLen = subseq(smallString, output);

    for (int i = 0; i < smallAnsLen; i++) {
        output[i + smallAnsLen] = input[0] + output[i];
    }

    return (2 * smallAnsLen);
}

int main(){
    string input;
    cin >> input;
    string output[1000];
    int count = subseq(input, output);

    for (int i = 0; i < count; i++){
        cout << output[i] << endl;
    }
}