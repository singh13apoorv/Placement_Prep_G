#include <bits/stdc++.h>
using namespace std;

void removeConsecutiveDuplicates(char input[]) {
    char ans[strlen(input)];
    int j = 1;
    ans[0] = input[0];

    for (int i = 1; i < strlen(input); i++){
        if (input[i] == ans[j - 1]){
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
    cin >> str;
    removeConsecutiveDuplicates(str);
    cout << str;
}