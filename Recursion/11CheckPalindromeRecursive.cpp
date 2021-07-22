#include <bits/stdc++.h>
using namespace std;

void helper(char input[], int start, int end){
    char ans[strlen(input)];
    int j = 0;
    for (int i = start; i <= end; i++){
        ans[j] = input[i];
        j++;
    }
    ans[j] = '\0';
    strcpy(input, ans);
}

bool checkPalindrome(char input[]) {
    // Write your code here
	if (strlen(input) == 1 || strlen(input) == 0){
        return true;
    }
    
    if (input[0] != input[strlen(input) - 1]){
        return false;
    }
    helper(input, 1, (strlen(input) - 2));
    bool smallAns = checkPalindrome(input);
    
    return (true && smallAns);
}

int main() {
    char input[50];
    cin >> input;
    
    if(checkPalindrome(input)) {
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }
}
