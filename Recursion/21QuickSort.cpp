#include <bits/stdc++.h>

int partition(int input[], int si, int ei) {
    int countSmaller = 0;
    
    for (int i = si; i <= ei; i++) {
        if (input[i] < input[si]) {
            countSmaller++;
        }
    }
    
    int temp = input[si];
    input[si] = input[si + countSmaller];
    input[si + countSmaller] = temp;
    
    int i = si;
    int j = ei;
    
    while (i < si + countSmaller && j > si + countSmaller) {
        if (input[i] >= input[si + countSmaller] && input[j] >= input[si + countSmaller]) {
            j--;
        }
        else if (input[i] < input[si + countSmaller] && input[j] < input[si + countSmaller]) {
            i++;
        }
        else if (input[i] < input[si + countSmaller] && input[j] >= input[si + countSmaller]){
            i++;
            j--;
        }
        else {
            int temp = input[i];
            input[i] = input[j];
            input[j] = temp;
            i++;
            j--;
        }
    }
    return (si + countSmaller);
}

void quick_sort(int input[], int si, int ei) {
    if (si >= ei) {
        return;
    }
    
    int rightPos = partition(input, si, ei);
    quick_sort(input, si, rightPos - 1);
    quick_sort(input, rightPos + 1, ei);
}
void quickSort(int input[], int size) {
    /* Don't write main().
    Don't read input, it is passed as function argument.
    Change in the given array itself.
    Taking input and printing output is handled automatically.
  */
	quick_sort(input, 0, size - 1);
}

int main(){
    int n;
    cin >> n;
    int *input = new int[n];
    
    for(int i = 0; i < n; i++) {
        cin >> input[i];
    }
    
    quickSort(input, n);
    for(int i = 0; i < n; i++) {
        cout << input[i] << " ";
    }
    delete [] input;
}
