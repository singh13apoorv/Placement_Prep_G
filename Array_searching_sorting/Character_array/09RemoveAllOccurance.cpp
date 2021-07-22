#include <bits/stdc++.h>
using namespace std;

void removeAllOccurrencesOfChar(char input[], char c) {
    char ans[strlen(input)];
    int j = 0;
    
    for (int i = 0; i < strlen(input); i++){
        if (input[i] == c){
            continue;
        }
        ans[j] = input[i];
        j++;
    }
    strcpy(input, ans);
}

int main() {
    int size = 1e6;
    char str[size];
    cin.getline(str, size);
    char c;
    cin >> c;
    removeAllOccurrencesOfChar(str, c);
    cout << str;
}