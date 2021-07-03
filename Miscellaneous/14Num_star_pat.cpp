#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= (n - i + 1); j++){
			cout << j;
		}

		for (int k = 1; k < i; k++){
			cout << '*';
		}

		for (int m = 1; m < i; m++){
			cout << '*';
		}

		for (int l = (n - i + 1); l >= 1; l--){
			cout << l;
		}
		cout << endl;
	}
	return 0;
}