#include <bits/stdc++.h>
using namespace std;

void minLengthWord(char input[], char output[]){
    int min_len = INT_MAX;
    int j = 0;
    char temp[strlen(input)];
    
    for (int i = 0; input[i] != '\0'; i++){
        if (input[i] == ' '){
            if (strlen(temp) < min_len){
                min_len = strlen(temp);
                strcpy(output, temp);
            }
            memset(temp, 0, strlen(input));
            j = 0;
            continue;
        }
        temp[j] = input[i];
        j++;
    }
}

int main(){
    char ch[10000], output[10000];
    cin.getline(ch, 10000);
    minLengthWord(ch, output);
    cout << output << endl;
}