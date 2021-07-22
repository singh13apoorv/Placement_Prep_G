#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

bool isPermutation(char input1[], char input2[]) {
    unordered_map<char, int> umap;
    int j = 0;

    while (j < strlen(input1)){
        if (umap.find(input1[j]) == umap.end()){
            umap.insert(make_pair(input1[j], 1));
        }
        else {
            umap.at(input1[j]) += 1;
        }
        j++;
    }

    int i = 0;

    while (i < strlen(input2)){
        if (umap.find(input2[i]) == umap.end()){
            return false;
        }
        else {
            if (umap.at(input2[i]) == 0){
                return false;
            }
            i++;
        }
    }
    return true;
}

int main() {
    int size = 1e6;
    char str1[size];
    char str2[size];
    cin >> str1 >> str2;
    cout << (isPermutation(str1, str2) ? "true" : "false");
}
