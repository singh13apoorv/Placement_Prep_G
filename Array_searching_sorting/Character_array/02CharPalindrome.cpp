#include <bits/stdc++.h>
using namespace std;

bool checkPalindrome(char str[]){
	int i = 0;
	int j = 0;

	while (str[j] != '\0'){
		j++;
	}
	j -= 1;
	while (i <= j){
		if (str[i] != str[j]){
			return false;
		}
		i++;
		j--;
	}

	return true;
}

int main(){
	char str[100];
	cin >> str;

	cout << checkPalindrome(str) << endl;
	return 0;
}