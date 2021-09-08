#include <bits/stdc++.h>
using namespace std;

bool isMaxHeap(int arr[], int n) {
    for (int i = 0; i < n; i++){
        int parent = i;
        int leftChild = 2 * parent + 1;
        int rightChild = 2 * parent + 2;
        
        if (leftChild < n && arr[parent] < arr[leftChild]){
            return false;
        }
        if (rightChild < n && arr[parent] < arr[rightChild]){
            return false;
        }
    }
    
    return true;
}

int main() {
    int n;
    cin >> n;
    int *arr = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << (isMaxHeap(arr, n) ? "true\n" : "false\n");

    delete[] arr;
}