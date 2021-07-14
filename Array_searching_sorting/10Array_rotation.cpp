#include <bits/stdc++.h>
using namespace std;

void rotate(int *input, int d, int n){
	int i = d;
	int j = n - 1;
	while (i < j){
		int temp = input[i];
		input[i] = input[j];
		input[j] = temp;

		i++;
		j--;
	}

	i = 0;
	j = d - 1;

	while (i < j){
		int temp = input[i];
		input[i] = input[j];
		input[j] = temp;

		i++;
		j--;
	}

	i = 0;
	j = n - 1;

	while (i < j){
		int temp = input[i];
		input[i] = input[j];
		input[j] = temp;

		i++;
		j--;
	}
}

int main(){
	int n;
	cin >> n;

	int input[n];
	for (int i = 0; i < n; i++){
		cin >> input[i];
	}

	int d;
	cin >> d;

	rotate(input, d, n);

	for (int i = 0; i < n; i++){
		cout << input[i] << " ";
	}
	cout << endl;

	return 0;
}