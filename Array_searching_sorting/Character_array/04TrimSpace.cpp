#include <bits/stdc++.h>
using namespace std;

void trimSpaces(char input[]){
	int i = 0;
	int j = i + 1;

	while (input[j] != '\0'){
		if (input[i] == ' ' && input[j] != ' '){
			char temp = input[i];
			input[i] = input[j];
			input[j] = temp;
			i++;
			j++;
		}
		else if (input[i] == ' ' && input[j] == ' ') {
			j++;
		}
		else {
			i++;
			j++;
		}
	}
}

int main(){
	char input[100];
	cin.getline(input, 100);

	trimSpaces(input);
	cout << input << endl;

	return 0;
}