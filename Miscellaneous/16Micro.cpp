#include <bits/stdc++.h>
using namespace std;

int sum(int n){
	int ans = 0;
	while (n != 0){
		ans += n % 10;
		n /= 10;
	}
	return ans;
}

int Gnum(int n){
	int k = n + (10 - n % 10) - 1;
	int j = sum(n) / 10;
	if (2 * sum(n) <= sum(k)){
		int i = n + 1;
		while (i <= k){
			if (sum(i) == (2 * sum(n))){
				return i;
			}
			i++;
		}
	}
	else {
		while (true){
			if (sum(k) == 2 * sum(n)){
				return k;
			}
			k += pow(10, j);
		}
	}
	return -1;
}

int main(){
	int n;
	cin >> n;

	cout << Gnum(n) << endl;
	return 0;
}