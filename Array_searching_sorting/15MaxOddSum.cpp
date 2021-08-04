#include <bits/stdc++.h>
using namespace std;

int MaxOddSum(int *arr, int size){
    int min_odd = INT_MAX;

    bool isOdd = false;
    int sum = 0;
    for (int i=0 ; i<size ; i++)
    {
        if (arr[i] > 0)
            sum = sum + arr[i];

        if (arr[i]%2 != 0)
        {
            isOdd = true;
            if (min_odd> abs(arr[i]))
                min_odd = abs(arr[i]);
        }
    }

    if (isOdd == false)
        return -1;

    if (sum%2 == 0)
        sum = sum - min_odd;

    return sum;
}

int main(){
    int n;
    cin >> n;
    int arr[n];

    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }

    cout << MaxOddSum(arr, n) << endl;

    return 0;
}