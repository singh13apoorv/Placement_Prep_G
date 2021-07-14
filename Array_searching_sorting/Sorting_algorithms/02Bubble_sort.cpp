#include <bits/stdc++.h>
using namespace std;

void bubbleSort(int *input, int n){
	int start = 0;
	int end = n - 1;

	while (start < end){
		int i = start;
		int j = i + 1;

		while (j <= end){
			if (input[i] > input[j]){
				int temp = input[i];
				input[i] = input[j];
				input[j] = temp;
			}
			i++;
			j++;
		}
		end--;
	}
}

int main(){
	int n;
	cin >> n;

	int input[n];
	for (int i = 0; i < n; i++){
		cin >> input[i];
	}

	bubbleSort(input, n);

	for (int i = 0; i < n; i++){
		cout << input[i] << " ";
	}
	cout << endl;
	return 0;
}