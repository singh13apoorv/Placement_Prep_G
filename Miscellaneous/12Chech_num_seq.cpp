#include <bits/stdc++.h>
using namespace std;

int mod(int a, int b){

	if (a - b < 0){
		return ((-1) * (a - b)); 
	}
	return (a - b);
}

int main(){
	int n;
	cin >> n;
	int arr[n];

	for (int i = 0; i < n; i++){
		cin >> arr[i];
	}

	int count = 0;
	int y = mod(arr[1], arr[0]);
	int x = (arr[1] - arr[0]) / y;

	if (n == 2){
		cout << "true" << endl;
		return 0;
	}

	if (n == 1 || n == 0){
		cout << "false" << endl;
		return 0;
	}

	for (int i = 1; i < (n - 1); i++){
		if (arr[i + 1] - arr[i] == 0){
			cout << "false" << endl;
			return 0;
		}
		if (((arr[i + 1] - arr[i]) / mod(arr[i + 1], arr[i])) != x){
			x = ((arr[i + 1] - arr[i]) / mod(arr[i + 1], arr[i]));
			count++;
		}
		if (count > 1){
			cout << "false" << endl;
			return 0;
		}
	}
	cout << "true" << endl;

	return 0;
}