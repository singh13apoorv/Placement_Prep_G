#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;

	int arr[n];
	int lar1 = INT_MIN;

	for (int i = 0; i < n; i++){
		cin >> arr[i];
		if (arr[i] > lar1){
			lar1 = arr[i];
		}
	}

	int lar2 = INT_MIN;

	for (int i = 0; i < n; i++){
		if (arr[i] > lar2 && arr[i] < lar1){
			lar2 = arr[i];
		}
	}

	cout << lar2 << endl;
	return 0;
}