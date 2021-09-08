#include <bits/stdc++.h>
using namespace std;

int buyTicket(int *arr, int n, int k) {
    // Write your code here
    queue<int> q;
    priority_queue<int> pq;
    
    for (int i = 0; i < n; i++){
        q.push(i);
    }
    
    for (int i = 0; i < n; i++){
        pq.push(arr[i]);
    }
    
    int count = 0;
    while (!pq.empty()){
        if (arr[q.front()] == pq.top()){
            count++;
            if (q.front() == k){
                break;
            }
            q.pop();
            pq.pop();
        }
        else {
            int temp = q.front();
            q.pop();
            q.push(temp);
        }
    }
    
    return count;
}

int main() {
    int n;
    cin >> n;

    int *arr = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int k;
    cin >> k;

    cout << buyTicket(arr, n, k);

    delete[] arr;
}