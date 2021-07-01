#include <bits/stdc++.h>
using namespace std;

int sum(int n){
	int s = 0;
	for (int i = 0; i <= n; i++){
		s += i;
	}
	return s;
}

int prod(int n){
	int p = 1;
	for (int i = 1; i <= n; i++){
		p *= i;
	}
	return p;
}

int main(){
	int n;
	int c;

	cin >> n;
	cin >> c;

	if (c == 1){
		cout << sum(n) << endl;
	}
	else if (c == 2){
		cout << prod(n) << endl;
	}
	else {
		cout << -1 << endl;
	}
	return 0;
}