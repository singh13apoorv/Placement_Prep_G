#include <bits/stdc++.h>
using namespace std;

void merge(int arr[], int si, int ei) {
    int size = ei - si + 1;
    int mid = (si + ei) / 2;
    int i = si;
    int j = mid + 1;
    int k = 0;
    int * out = new int[size];

    while (i <= mid && j <= ei) {
        if (arr[i] < arr[j]) {
            out[k] = arr[i];
            i++;
            k++;
        }
        else {
            out[k] = arr[j];
            k++;
            j++;
        }
    }

    while (i <= mid) {
        out[k] = arr[i];
        k++;
        i++;
    }

    while (j <= ei) {
        out[k] = arr[j];
        k++;
        j++;
    }

    int m = 0;

    for (int i = si; i <= ei; i++) {
        arr[i] = out[m];
        m++;
    }
    delete [] out;
}

void merge_sort(int arr[], int si, int ei){
    if (si >= ei){
        return;
    }

    int mid = (si + ei) / 2;
    merge_sort(arr, si, mid);
    merge_sort(arr, mid + 1, ei);
    merge(arr, si, ei);
}

void mergeSort(int arr[], int size) {
    merge_sort(arr, 0, size - 1);
}

int main() {
    int n;
    cin >> n;
    int * input = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> input[i];
    }

    mergeSort(input, n);

    for (int i = 0; i < n; i++) {
        cout << input[i] << " ";
    }
    cout << endl;
    delete [] input;
}