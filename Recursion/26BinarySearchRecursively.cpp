#include <bits/stdc++.h>

int binarySearch(int input[], int si, int ei, int element){
    if (si > ei){
        return -1;
    }
    
    int mid = (si + ei) / 2;
    
    if (input[mid] == element){
        return mid;
    }
    if (input[mid] > element){
        return binarySearch(input, si, mid - 1, element);
    }
    return binarySearch(input, mid + 1, ei, element);
}

int binarySearch(int input[], int size, int element) {
    // Write your code here
    return binarySearch(input, 0, size - 1, element);
}

int main() {
    int input[100000],length,element, ans;
    cin >> length;
    for(int i =0;i<length;i++)
    { 
        cin >> input[i];;
    }

    cin>>element;
    ans = binarySearch(input, length, element);
    cout<< ans << endl;
}