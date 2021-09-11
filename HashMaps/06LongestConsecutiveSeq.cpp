#include <unordered_map>
#include <bits/stdc++.h>
using namespace std;

vector<int> longestConsecutiveIncreasingSequence(int *arr, int n) {
    // Your Code goes here
    unordered_map<int, bool> umap;
    
    for (int i = 0; i < n; i++){
        if (umap.count(arr[i]) > 0){
            continue;
        }
        
        umap[arr[i]] = true;
    }
    
    int len = 0;
    int maxLen = INT_MIN;
    int start;
    int end;
    vector<int> ans;
    
    for (int i = 0; i < n; i++){
        if (umap.at(arr[i]) == false){
            continue;
        }
        else {
            int startval = arr[i];
            int endval = arr[i];
            while (umap.count(endval) > 0){
                umap.at(endval) = false;
                len++;
                endval += 1;
            }
            endval -= 1;
            
            if (len > maxLen){
                maxLen = len;
                start = startval;
                end = endval;
            }
            len = 0;
        }
    }
    
    ans.push_back(start);
    ans.push_back(end);
    
    return ans;
}

int main() {
    int size;
    cin >> size;

    int* arr = new int[size];

    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    vector<int> ans = longestConsecutiveIncreasingSequence(arr, size);

    cout << ans[0];
    if (ans.size() > 1) {
        cout << " " << ans[ans.size() - 1];
    }

    delete[] arr;
}