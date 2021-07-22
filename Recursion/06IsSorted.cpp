#include <bits/stdc++.h>
using namespace std;

bool is_sorted(int *arr, int size){
    if (size == 0 || size == 1) {
        return true;
    }
    if (arr[0] > arr[1]) {
        return false;
    }

    bool isSmallerSorted = is_sorted(arr + 1, size - 1);
    return isSmallerSorted;
}

int main(){
    int arr[5] = {1, 2, 3, 6, 5};

    cout << is_sorted(arr, 5) << endl;
}