#include <bits/stdc++.h>
using namespace std;

void printSubstrings(char input[]){
	int i = 0;
	int j = 0; 
	int k = 0;

	while (input[k] != '\0'){
		i = k;
		while (input[i] != '\0'){
			j = k;
			while (j <= i){
				cout << input[j];
				j++;
			}
			cout << endl;
			i++;
		}
		k++;
	}
}

int main(){
	char input[100];
	cin >> input;

	printSubstrings(input);
	return 0;
}