#include <bits/stdc++.h>

int getCodes(string input, string output[10000]) {
    /*
    You are given the input text and output string array. Find all possible codes and store in the output string array. Donât print the codes.
    Also, return the number of codes return to the output string. You do not need to print anything.
    */
    if (input.size() == 0){
        output[0] = "";
        return 1;
    }
    
    string s1[10000];
    string s2[10000];
    
    int sAns1 = getCodes(input.substr(1), s1);
    int sAns2;
    
    int k2 = input[1] - '0';
    int k1 = input[0] - '0';
    int k = k1 * 10 + k2;
    
    int row = 0;
    
    for (int i = 0; i < sAns1; i++){
        int j = input[0] - '0';
        char support1 = ('a' + j - 1);
        output[row] = support1 + s1[i];
        row++;
    }
    
    if (k >= 10 && k <= 26){
        sAns2 = getCodes(input.substr(2), s2);
        for (int i = 0; i < sAns2; i++){
            int j = k;
            char support2 = ('a' + j - 1);
            output[row] = support2 + s2[i];
            row++;
        }
    }
    
    return row;
}

int main(){
    string input;
    cin >> input;

    string output[10000];
    int count = getCodes(input, output);
    for(int i = 0; i < count && i < 10000; i++)
        cout << output[i] << endl;
    return 0;
}
