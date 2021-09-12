#include <unordered_map>
#include <bits/stdc++.h>
using namespace std;

int lengthOfLongestSubsetWithZeroSum(int* arr, int n) {
    // Write your code here
    unordered_map<int, int> umap;
    int maxLen = INT_MIN;
    int sum = 0;
    
    for (int i = 0; i < n; i++){
        sum += arr[i];
        int len = 0;
        if (umap.count(sum) > 0){
            if (sum == 0){
                len = i + 1;
            }
            else {
                int val = umap.at(sum);
                len = i - val;
            }
        }
        else {
            umap[sum] = i;
            if (sum == 0){
                len = i + 1;
            }
        }
        
        if (len > maxLen){
            maxLen = len;
        }
    }
    
    return maxLen;
}

int main() {
    int size;
    cin >> size;

    int* arr = new int[size];

    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    cout << lengthOfLongestSubsetWithZeroSum(arr, size);

    delete[] arr;
}