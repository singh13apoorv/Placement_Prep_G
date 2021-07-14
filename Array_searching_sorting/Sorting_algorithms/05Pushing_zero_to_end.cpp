#include <bits/stdc++.h>
using namespace std;

void pushZeroesEnd(int *input, int n){
	int i = 0;
	int j = i + 1;

	while (j < n){
		if (input[i] == 0 && input[j] == 0){
			j++;
		}
		else if (input[i] == 0 && input[j] != 0){
			int temp = input[i];
			input[i] = input[j];
			input[j] = temp;

			i++;
			j++;
		}
		else {
			i++;
			j++;
		}
	}
}

int main(){
	int n;
	cin >> n;

	int input[n];
	for (int i = 0; i < n; i++){
		cin >> input[i];
	}

	pushZeroesEnd(input, n);

	for (int i = 0; i < n; i++){
		cout << input[i] << " ";
	}
	cout << endl;

	return 0;
}