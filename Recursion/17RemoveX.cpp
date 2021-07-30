#include <cstring>
#include <bits/stdc++.h>

void removeX(char input[]) {
    // Write your code here
	if (strlen(input) == 0){
        return;
    }
    removeX(input + 1);
    
    if (input[0] == 'x'){
        for (int i = 1; i <= strlen(input); i++){
            input[i - 1] = input[i];
        }
    }
}

int main() {
    char input[100];
    cin.getline(input, 100);
    removeX(input);
    cout << input << endl;
}

