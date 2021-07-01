#include <bits/stdc++.h>
using namespace std;

long long int po(int a, int b){
	long long int ans = 1;

	for (int i = 1; i <= b; i++){
		ans *= a;
	}

	return ans;
}

int main(){
	int n;
	long long int ans = 0;
	int count = 0;
	cin >> n;

	if (n == 0){
		cout << 0 << endl;
		return 0;
	}

	while (n != 1){
		ans += (n % 2) * po(10, count);
		n = n / 2;
		count++;
	}
	ans += po(10, count);
	cout << ans << endl;

	return 0;
}