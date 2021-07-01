#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	int count = 0;
	double x = 0;
	int ans;
	int temp;
	cin >> n;

	if (n < 0){
		temp = (-1) * n;
	}
	else {
		temp = n;
	}

	while (temp != 0){
		x += (temp % 10) * pow(10, -count);
		temp = temp/10;
		count++;
	}
	ans = (x * pow(10, count - 1));

	if (n < 0){
		cout << (-1) * ans << endl;
	}
	else {
		cout << ans << endl;
	}

	return 0;
}