#include <unordered_map>
#include <bits/stdc++.h>
using namespace std;

string uniqueChar(string str) {
	// Write your code here
    unordered_map<char, bool> umap;
    string ans = "";
    
    for (int i = 0; i < str.size(); i++){
        if (umap.count(str[i]) > 0){
            continue;
        }
        
        umap[str[i]] = true;
        ans += str[i];
    }
    
    return ans;
}

int main() {
    string str;
    cin >> str;
    cout << uniqueChar(str);
}