#include <bits/stdc++.h>
using namespace std;

void intersection(int *input1, int *input2, int size1, int size2){
	int i = 0; 
	int j = 0; 
	int k = 0;
	int arr[100];

	while (i < size1 && j < size2){
		if (input1[i] == input2[j]){
			arr[k] = input1[i];
			input2[j] = INT_MIN;
			j = 0;
			i++;
			k++;
		}
		j++;
		cout << j << endl;

		if (j == (size2 - 1) && i < size1){
			j = 0;
			i++;
		}
	}

	for (int l = 0; l < k; l++){
		cout << arr[l] << " ";
	}
	cout << endl;
}

int main(){
	int t;
	cin >> t;

	while (t){
		int n;
		cin >> n;

		int input1[n];
		for (int i = 0; i < n; i++){
			cin >> input1[i];
		}

		int m;
		cin >> m;

		int input2[m];
		for (int i = 0; i < m; i++){
			cin >> input2[i];
		}

		intersection(input1, input2, n, m);
		t--;
	}
	return 0;
}