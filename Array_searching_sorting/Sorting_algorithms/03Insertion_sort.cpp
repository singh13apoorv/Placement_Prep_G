#include <bits/stdc++.h>
using namespace std;

void insertionSort(int *input, int n){
	int i = 1;

	while(i < n){
		int j = i - 1;
		int current = input[i];

		while (j >= 0){
			if (current < input[j]){
				input[j + 1] = input[j];
			}
			else {
				break;
			}
			j--;
		}

		input[j + 1] = current;
		i++;
	}
}

int main(){
	int n;
	cin >> n;

	int input[n];
	for (int i = 0; i < n; i++){
		cin >> input[i];
	}

	insertionSort(input, n);

	for (int i = 0; i < n; i++){
		cout << input[i] << " ";
	}
	cout << endl;

	return 0;
}