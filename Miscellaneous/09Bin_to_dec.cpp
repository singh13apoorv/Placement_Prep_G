#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	int ans = 0;
	int count = 0;
	cin >> n;

	while (n != 0){
		ans += ((n % 10) * pow(2, count));
		n = n / 10;
		count++;
	}
	cout << ans << endl;
	return 0;
}