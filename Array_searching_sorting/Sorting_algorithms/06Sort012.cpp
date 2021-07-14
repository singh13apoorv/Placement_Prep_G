#include <bits/stdc++.h>
using namespace std;

void sort012(int *arr, int n){
	int low = 0;
	int high = n - 1;
	int i = 0;

	while (i <= high){
		if (arr[low] == 0 && arr[high] == 2){
			low ++;
			high--;
			i++;
		}
		else {
			if (arr[i] == 0){
				int temp = arr[i];
				arr[i] = arr[low];
				arr[low] = temp;

				low++;
				i++;
			}
			else if (arr[i] == 2){
				int temp = arr[i];
				arr[i] = arr[high];
				arr[high] = temp;

				high--;
			}
			else {
				i++;
			}
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

	sort012(input, n);

	for (int i = 0; i < n; i++){
		cout << input[i] << " ";
	}
	cout << endl;

	return 0;
}