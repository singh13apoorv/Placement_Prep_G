#include <bits/stdc++.h>
using namespace std;

void stringCompression(char input[]) {
    char ans[strlen(input)];

    int i = 0;
    int j = 0;
    int count = 0;
    int k = 0;

    while (input[i] != '\0'){
        if (input[i] == input[j]){
            if (i == j && input[i + 1] == '\0'){
                ans[k] = input[i];
                ans[k + 1] = '\0';
                i++;
                j++;
                continue;
            }
            j++;
            count++;
            continue;
        }
        if (count > 1){
            if (input[j] == '\0'){
                ans[k] = input[i];
                ans[k + 1] = '0' + count;
                ans[k + 2] = '\0';
                i = j;
                continue;
            }
            ans[k] = input[i];
            ans[k + 1] = '0' + count;
            count = 0;
            k += 2;
            i = j;
            continue;
        }
        ans[k] = input[i];
        k++;
        i = j;
        count = 0;
    }
    strcpy(input, ans);
}

int main() {
    int size = 1e6;
    char str[size];
    cin >> str;
    stringCompression(str);
    cout << str;
}