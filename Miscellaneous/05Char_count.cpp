#include <bits/stdc++.h>
using namespace std;

int main(){
	char c;
	int countl = 0;
	int countn = 0;
	int counts = 0;
	c = cin.get();

	while (c != '$'){
		if (c >= 'a' && c <= 'z'){
			countl++;
		}
		else if (c >= '0' && c <= '9'){
			countn++;
		}
		else if (c == ' ' || c == '\t' || c == '\n'){
			counts++;
		}

		c = cin.get();
	}

	cout << countl << " " << countn << " " << counts << endl;

	return 0;}