#include <bits/stdc++.h>
using namespace std;

int pairsum(int *input, int size, int x){
	int count = 0;
	int j = 0;
	int i = j + 1;

	while (i < size) {
		if (input[j] + input[i] == x){
			count++;
		}
		if (i == (size - 1)){
			j++;
			i = j + 1;
			continue;
		}
		i++;
	}
	return count;
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

		int x;
		cin >> x;

		cout << pairsum(input, n, x) << endl;
		t--;
	}
	return 0;
}