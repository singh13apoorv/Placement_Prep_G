#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	int count = 0;
	cin >> n;
	int i = 1;

	while (count != n){
		if ((3 * i + 2) % 4 != 0){
			cout << (3 * i + 2) << " ";
			count++;
		}
		i++;
	}
	return 0;
}