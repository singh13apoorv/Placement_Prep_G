#include <bits/stdc++.h>
using namespace std;

void SelectionSort(int input[], int n){
	int start = 0; 
	int end = n - 1;

	while (start < end - 1){
		int index = start;
		int min = input[start];

		for (int j = start; j <= end; j++){
			if (input[j] < min){
				min = input[j];
				index = j;
			}
		}

		//Swap
		int temp = input[start];
		input[start] = min;
		input[index] = temp;

		start++;
	}
}

int main(){
	int n;
	cin >> n;

	int input[n];
	for (int i = 0; i < n; i++){
		cin >> input[i];
	}

	SelectionSort(input, n);

	for (int i = 0; i < n; i++){
		cout << input[i] << " ";
	}
	cout << endl;

	return 0;
}