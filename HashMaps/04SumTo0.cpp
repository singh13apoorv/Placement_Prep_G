#include <unordered_map>
#include <bits/stdc++.h>
using namespace std;

int pairSum(int *arr, int n) {
	// Write your code here
    unordered_map<int, int> umap;
    int pair = 0;
    
    for (int i = 0; i < n; i++){
        if (umap.count(-arr[i]) > 0){
            pair += umap.at(-arr[i]);
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

    int* arr = new int[n];

    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    cout << pairSum(arr, n);

    delete[] arr;
}