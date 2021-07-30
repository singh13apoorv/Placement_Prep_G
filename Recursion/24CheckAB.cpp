#include <cstring>
#include <bits/stdc++.h>

bool checkAB(char input[]) {
	// Write your code here
	if (strlen(input) == 0){
        return true;
    }
    
    if (input[0] != 'a'){
        return false;
    }
    if (input[1] == 'b' && input[2] != 'b'){
        return false;
    }
    bool smallOutput;
    if (input[1] == 'a'){
        smallOutput = checkAB(input + 1);
    }
    else {
        smallOutput = checkAB(input + 3);
    }
    
    return (true && smallOutput);
}

int main() {
    char input[100];
    bool ans;
    cin >> input;
    ans=checkAB(input);
    if(ans)
        cout<< "true" << endl;
    else
        cout<< "false" << endl;
}