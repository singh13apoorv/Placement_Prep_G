#include <bits/stdc++.h>

int keypad(int num, string output[]){
    /* Insert all the possible combinations of the integer number into the output string array. You do not need to
    print anything, just return the number of strings inserted into the array.
    */
    string keys[10]={"","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    if (num == 0){
        output[0] = "";
        return 1;
    }
    
    int smallAnsLen = keypad(num / 10, output);
    int sizeOfstr = 0;
    int j = 0;
    int k = 1;
    for (int i = 0; i < smallAnsLen, j < keys[(num % 10) - 1].size() - 1; i++){
        output[i + (j + 1) * smallAnsLen] = output[i];
        if (i == smallAnsLen && j != keys[(num % 10) - 1].size() - 1){
            i = 0;
            j++;
        }
    }
    j = 0;
    for (int i = 0; i < smallAnsLen, j < keys[(num % 10) - 1].size(); i++) {
        if (i == smallAnsLen) {
            i = 0;
            j++;
        }
        output[i + j * smallAnsLen] = output[i + j * smallAnsLen] + keys[(num % 10) - 1][j];
    }
    return (keys[(num % 10) - 1].size() * smallAnsLen);
}

int main(){
    int num;
    cin >> num;

    string output[10000];
    int count = keypad(num, output);
    for(int i = 0; i < count && i < 10000; i++){
        cout << output[i] << endl;
    }
    return 0;
}