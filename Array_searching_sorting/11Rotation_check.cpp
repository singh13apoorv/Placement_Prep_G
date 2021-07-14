#include <bits/stdc++.h>
using namespace std;

int arrayRotationCheck(int *input, int size){
	int check[size];

	int d = 0;

	while (d < size){
		for (int i = 0; i < size; i++){
			check[i] = input[i];
		}
		
		int i = d;
		int j = size - 1;
		while (i < j){
			int temp = check[i];
			check[i] = check[j];
			check[j] = temp;

			i++;
			j--;
		}

		i = 0;
		j = d - 1;

		while (i < j){
			int temp = check[i];
			check[i] = check[j];
			check[j] = temp;

			i++;
			j--;
		}

		i = 0;
		j = size - 1;

		while (i < j){
			int temp = check[i];
			check[i] = check[j];
			check[j] = temp;

			i++;
			j--;
		}
		bool b = false;

		for (int i = 0; i < (size - 1); i++){
			if (check[i] > check[i + 1]){
				b = true;
				break;
			}
		}
		if (b == false){
			break;
		}
		d++;
	}
	return d;
}

int main(){
	int n;
	cin >> n;

	int input[n];
	for (int i = 0; i < n; i++){
		cin >> input[i];
	}

	cout << arrayRotationCheck(input, n) << endl;

	return 0;
}