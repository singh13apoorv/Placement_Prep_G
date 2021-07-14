#include <bits/stdc++.h>
using namespace std;

void reverseStringWordWise(char input[]){
	int k = 0;
	int count = 0;

	while (input[k] != '\0'){
		if (input[k] == ' '){
			count++;
		}
		k++;
	}

	int tind = k - 1;
	int l = 0;

	while (l < tind){
		int temp = input[l];
		input[l] = input[tind];
		input[tind] = temp;

		l++;
		tind--;
	}

	int i = 0;
	int j = 0;
	int index;
	int t = 0;

	while (t <= count){
		while (input[j] != ' ' && input[j] != '\0'){
			j++;
		}
		index = j - 1;

		while (i < index){
			int temp = input[i];
			input[i] = input[index];
			input[index] = temp;

			i++;
			index--;
		}
		j += 1;
		i = j;

		t++;
	}
}

int main(){
	char input[100];
	cin.getline(input, 100);

	reverseStringWordWise(input);
	cout << input << endl;

	return 0;
}