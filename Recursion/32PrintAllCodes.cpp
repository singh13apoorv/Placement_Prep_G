#include <bits/stdc++.h>

void printAllPossibleCodes(string input, string output){
    if (input.size() == 0){
        cout << output << endl;
        return;
    }
	
    int l = input[0] - '0';
    char support = 'a' + l - 1;
    //output += support;
    printAllPossibleCodes(input.substr(1), output+support);
    //output = output.substr(0, output.size() - 1);
    
    
    int k1 = input[0] - '0';
    int k2 = input[1] - '0';
    int k = 10*k1 + k2;
    
    if (k >= 10 && k <= 26){
        char supp = 'a' + k - 1;
        //output += supp;
        printAllPossibleCodes(input.substr(2), output+supp);
    }
}

void printAllPossibleCodes(string input) {
    /*
    Given the input as a string, print all its possible combinations. You do not need to return anything.
    */
    string output = "";
    printAllPossibleCodes(input, output);
}


int main(){
    string input;
    cin >> input;

    printAllPossibleCodes(input);
    return 0;
}
