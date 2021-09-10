#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int main(){
    unordered_map<string, int> umap;

    umap["abc1"] = 1;
    umap["abc2"] = 2;
    umap["abc3"] = 3;
    umap["abc4"] = 4;
    umap["abc5"] = 5;
    umap["abc6"] = 6;

    unordered_map<string, int>::iterator it = umap.begin();

    while (it != umap.end()){
        cout << "Key: " << it -> first << "Value: " << it -> second << endl;
        it++;
    }

    return 0;
}