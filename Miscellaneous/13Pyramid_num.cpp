#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++){
		for (int j = 0; j < n - i; j++){
			cout << " ";
		}

		for (int k = i; k > 0; k--){
			cout << k;
		}

		for (int l = 2; l <= i; l++){
			cout << l;
		}
		cout << endl;
	}

	return 0;
}