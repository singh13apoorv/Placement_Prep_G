#include <unordered_map>
#include <bits/stdc++.h>
using namespace std;

int highestFrequency(int arr[], int n) {
    // Write your code here
    unordered_map<int, int> umap;
    
    for (int i = 0; i < n; i++){
        if (umap.count(arr[i]) > 0){
            umap.at(arr[i])++;
        }
        else {
            umap[arr[i]] = 1;
        }
    }
    
    int ans;
    int val = INT_MIN;
    
    for (int i = 0; i < n; i++){
        if (umap.count(arr[i]) > 0){
            if (umap.at(arr[i]) > val){
                val = umap.at(arr[i]);
                ans = arr[i];
            }
        }
    }
    
    return ans;
}

int main() {
    int n;
    cin >> n;

    int* arr = new int[n];

    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    cout << highestFrequency(arr, n);

    delete[] arr;
}