#include <bits/stdc++.h>
using namespace std;

int arrayRotateCheck(int *input, int size){
	int i = 0;
	while (i < (size - 1)){
		if (input[i] > input[i + 1]){
			return i + 1;
		}
		i++;
	}
	return 0;
}

int main(){
	int n;
	cin >> n;

	int input[n];
	for (int i = 0; i < n; i++){
		cin >> input[i];
	}

	cout << arrayRotateCheck(input, n) << endl;

	return 0;
}