#include <bits/stdc++.h>
using namespace std;

int findSecondLargest(int *input, int n) {
	int max = INT_MIN;
	int smax = INT_MIN;
	int i = 0;

	while (i < n){
		if (max < input[i]){
			max = input[i];
		}
		i++;
	}
	i = 0;

	while (i < n){
		if (smax < input[i] && max > input[i]){
			smax = input[i];
		}
		i++;
	}
	
	return smax;
}

int main(){
	int n;
	cin >> n;

	int input[n];
	for (int i = 0; i < n; i++){
		cin >> input[i];
	}

	cout << findSecondLargest(input, n) << endl;

	return 0;
}