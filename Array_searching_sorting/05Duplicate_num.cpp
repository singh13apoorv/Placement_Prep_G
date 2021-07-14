#include <bits/stdc++.h>
using namespace std;

int duplicateNumber(int *arr, int n){
	int max = INT_MIN;
	for (int i = 0; i < n; i++){
		if (arr[i] > max){
			max = arr[i];
		}
	}

	int count[max + 1];
	for (int i = 0; i <= max; i++){
		count[i] = 0;
	}

	for (int i = 0; i < n; i++){
		count[arr[i]]++;
	}

	int i = 0;
	while (i <= max){
		if (count[i] == 2){
			break;
		}
		i++;
	}
	return i;
}

int main(){
	int t;
	cin >> t;

	while (t){
		int n;
		cin >> n;

		int arr[n];
		for (int i = 0; i < n; i++){
			cin >> arr[i];
		}

		cout << duplicateNumber(arr, n) << endl;
		t--;
	}
	return 0;
}