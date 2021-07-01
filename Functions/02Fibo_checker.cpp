#include <bits/stdc++.h>
using namespace std;

bool checkNum(int n){
	int f_n_2 = 0;
	int f_n_1 = 1;
	int fn;

	while (fn < n){
		fn = f_n_1 + f_n_2;
		f_n_2 = f_n_1;
		f_n_1 = fn;

		if (fn == n){
			return true;
		}
	}
	return false;
}

int main(){
	int n;
	cin >> n;

	cout << checkNum(n) << endl;
	return 0;
}