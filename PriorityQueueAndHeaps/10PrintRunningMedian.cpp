#include <bits/stdc++.h>
using namespace std;

void findMedian(int *arr, int n) {
    // Write your code here
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int> > minHeap;
    
    for (int i = 0; i < n; i++){
        if (maxHeap.size() == 0 && minHeap.size() == 0){
            maxHeap.push(arr[i]);
        }
        else if (maxHeap.top() > arr[i]){
            maxHeap.push(arr[i]);
        }
        else {
            minHeap.push(arr[i]);
        }
        int s = maxHeap.size() - minHeap.size();
        
        if (s > 1){
            int temp = maxHeap.top();
            maxHeap.pop();
            minHeap.push(temp);
        }
        else if (s < -1){
            int temp = minHeap.top();
            minHeap.pop();
            maxHeap.push(temp);
        }
        
        if ((maxHeap.size() + minHeap.size()) % 2 == 0){
            int t1 = minHeap.top();
            int t2 = maxHeap.top();
            cout << (t1 + t2) / 2 << " ";
        }
        else {
            if (maxHeap.size() > minHeap.size()){
                cout << maxHeap.top() << " ";
            }
            else {
                cout << minHeap.top() << " ";
            }
        }
    }
    cout << endl;
}

int main() {
    int n;
    cin >> n;

    int* arr = new int[n];

    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    findMedian(arr,n);

    delete[] arr;
}
