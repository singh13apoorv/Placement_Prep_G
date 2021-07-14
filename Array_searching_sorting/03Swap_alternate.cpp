#include <bits/stdc++.h>
using namespace std;

void swapAlternate(int *arr, int size){
	int i = 0;
	int j = 1;

	while (i < size && j < size){
		int temp = arr[i];
		arr[i] = arr[j];
		arr[j] = temp;

		i += 2;
		j += 2;
	}
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

		swapAlternate(arr, n);

		for (int i = 0; i < n; i++){
			cout << arr[i] << " ";
		}
		cout << endl;
		t--;
	}
	return 0;
}