#include <bits/stdc++.h>

void keypad(int num, string output) {
    string keys[10]={"","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    const int temp = num;
    if (num == 0){
        cout << output << endl;
        return;
    }
    
    for (int i = 0; i < keys[(num % 10) - 1].size(); i++){
        int myNum = num % 10;
        output = keys[(num % 10) - 1][i] + output;
        keypad(num / 10, output);
        output = output.substr(1);
    }
}

void printKeypad(int num){
    /*
    Given an integer number print all the possible combinations of the keypad. You do not need to return anything just print them.
    */
    string output = "";
    keypad(num, output);
}

int main(){
    int num;
    cin >> num;

    printKeypad(num);

    return 0;
}