#include <bits/stdc++.h>
using namespace std;

void heapSort(int arr[], int n) {
    // Write your code
    for(int i = 1; i < n; i++){
        int child = i;
        
        while (child > 0){
            int parent = (child - 1) / 2;
            
            if (arr[parent] > arr[child]){
                int temp = arr[parent];
                arr[parent] = arr[child];
                arr[child] = temp;
            }
            else {
                break;
            }
            child = parent;
        }
    }
    
    int size = n;
    
    while (size > 1){
        int temp = arr[0];
        arr[0] = arr[size - 1];
        arr[size - 1] = temp;
        
        size--;
        
        int parentIdx = 0;
        int leftChild = 2 * parentIdx + 1;
        int rightChild = 2 * parentIdx + 2;
        
        while (leftChild < size){
            int minIdx = parentIdx;
            
            if (arr[minIdx] > arr[leftChild]){
                minIdx = leftChild;
            }
            if (rightChild < size && arr[minIdx] > arr[rightChild]){
                minIdx = rightChild;
            }
            if (minIdx == parentIdx){
                break;
            }
            
            int temp = arr[parentIdx];
            arr[parentIdx] = arr[minIdx];
            arr[minIdx] = temp;
            
            parentIdx = minIdx;
            leftChild = 2 * parentIdx + 1;
            rightChild = 2 * parentIdx + 2;
        }
    }
}

int main() {
    int size;
    cin >> size;

    int *input = new int[size];

    for (int i = 0; i < size; i++) {
        cin >> input[i];
    } 

    heapSort(input, size);

    for (int i = 0; i < size; i++) {
        cout << input[i] << " ";
    } 

    delete[] input;
}