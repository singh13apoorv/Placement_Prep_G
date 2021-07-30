#include <cstring>
#include <math.h>
#include <bits/stdc++.h>

int stringToNumber(char input[]) {
    // Write your code here
	if (strlen(input) == 1){
        return (input[0] - '0');
    }
    
    int smallAns = stringToNumber(input + 1);
    int output = (input[0] - '0')*pow(10, strlen(input) - 1) + smallAns;
    
    return output;
}

int main() {
    char input[50];
    cin >> input;
    cout << stringToNumber(input) << endl;
}
