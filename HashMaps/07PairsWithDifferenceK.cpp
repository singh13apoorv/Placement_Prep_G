#include <unordered_map>
#include <bits/stdc++.h>
using namespace std;

int getPairsWithDifferenceK(int *arr, int n, int k) {
	// Write your code here
    unordered_map<int, int> umap;
    int pair = 0;
    
    for (int i = 0; i < n; i++){
        if (umap.count(arr[i] - k) > 0){
            pair += umap.at(arr[i] - k);
        }
        else if (umap.count(arr[i] + k) > 0){
            pair += umap.at(arr[i] + k);
        }
        if (umap.count(arr[i]) > 0){
            umap.at(arr[i])++;
        }
        else {
            umap[arr[i]]++;
        }
    }
    
    return pair;
}

int main() {
    int n;
    cin >> n;

    int *input = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> input[i];
    }

    int k;
    cin >> k;

    cout << getPairsWithDifferenceK(input, n, k);

    delete[] input;
}