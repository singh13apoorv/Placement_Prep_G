#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

vector<int> removeDuplicate(int* arr, int n){
    vector<int> output;
    unordered_map<int, bool> umap;

    for (int i = 0; i < n; i++){
        if (umap.count(arr[i])){
            continue;
        }

        umap[arr[i]] = true;
        output.push_back(arr[i]);
    }

    return output;
}

int main(){
    int arr[] = {1, 2, 1, 1, 2, 3, 3, 3, 5, 5, 5, 5, 6, 7, 6, 7, 6, 7};
    vector<int> ans = removeDuplicate(arr, 18);

    for (int i = 0; i < ans.size(); i++){
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}