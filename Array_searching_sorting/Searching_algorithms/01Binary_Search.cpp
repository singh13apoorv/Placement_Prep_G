#include <bits/stdc++.h>
using namespace std;

int binarySearch(int *input, int n, int val){
	int low = 0;
	int high = n - 1;

	while (low <= high){
		int mid = (low + high) / 2;
		int guess = input[mid];

		if (guess == val){
			return mid;
		}
		else if (guess < val) {
			low = mid + 1;
		}
		else {
			high = high - 1;
		}
	}
	return -1;
}

int main(){
	int t;
	cin >> t;

	while (t){
		int n;
		cin >> n;

		int input[n];
		for (int i = 0; i < n; i++){
			cin >> input[i];
		}

		int val;
		cin >> val;

		cout << binarySearch(input, n, val) << endl;
		t--;
	}
	return 0;
}