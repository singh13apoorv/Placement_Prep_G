#include <cstring>
#include <bits/stdc++.h>

void pairStar(char input[]) {
    // Write your code here
	if (strlen(input) == 0){
        return;
    }
    
    pairStar(input + 1);
    
    if (input[0] == input[1]) {
        for (int i = strlen(input); i >= 1; i--){
            input[i + 1] = input[i];
        }
        input[1] = '*';
    }
}

int main() {
    char input[100];
    cin.getline(input, 100);
    pairStar(input);
    cout << input << endl;
}