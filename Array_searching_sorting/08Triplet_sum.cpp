#include <bits/stdc++.h>
using namespace std;

int tripletSum(int *input, int size, int x){
	int count = 0;
	int i = 0;
	int j = i + 1;
	int k = j + 1;

	while (k < size){
		if(input[i] + input[j] + input[k] == x){
			count++;
		}
		if (k == (size - 1) && j == (size - 2)){
			i++;
			j = i + 1;
			k = j + 1;
			continue;
		}
		if (k == size - 1){
			j++;
			k = j + 1;
			continue;
		}
		k++;
	}
	return count;
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
		int x;
		cin >> x;

		cout << tripletSum(input, n, x) << endl;
		t--;
	}
	return 0;
}