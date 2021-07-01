#include <bits/stdc++.h>
using namespace std;

void celTable(int start, int end, int step){
	for (int i = start; i <= end; i += step){
		cout << i << " " << ((i - 32) * 5)/9 << endl;
	}
}

int main(){
	int s, e, w;
	cin >> s >> e >> w;

	celTable(s, e, w);
	return 0;
}
		
