#include <bits/stdc++.h>
using namespace std;

void sortZeroesAndOne (int *input, int size){
	int low = 0;
	int high = size - 1;

	while (low < high){
		if (input[low] == 0 && input[high] == 1){
			low++;
			high--;
		}
		else if (input[low] == 1 && input[high] == 0){
			int temp = input[low];
			input[low] = input[high];
			input[high] = temp;
			low++;
			high--;
		}
		else if (input[low] == 0 && input[high] == 0){
			low++;
		}
		else {
			high--;
		}
	}

	for (int j = 0; j < size; j++){
		cout << input[j] << " ";
	}
	cout << endl;
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

		sortZeroesAndOne(input, n);
		t--;
	}
	return 0;
}