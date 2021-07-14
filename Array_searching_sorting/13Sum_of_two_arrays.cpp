#include <bits/stdc++.h>
using namespace std;

void sumOfTwoArrays(int *input1, int size1, int *input2, int size2, int *output){
	int num1 = 0;
	for (int i = 0; i < size1; i++){
		num1 += pow(10, size1 - i - 1) * input1[i];
	}

	int num2 = 0;
	for (int i = 0; i < size2; i++){
		num2 += pow(10, size2 - i - 1) * input2[i];
	}

	int onum = num1 + num2;
	int temp = onum;

	int count = 0;
	while (temp != 0){
		temp /= 10;
		count++;
	}

	for (int i = count - 1; i >= 0; i--){
		output[i] = onum % 10;
		onum /= 10;
	}
}

int main(){
	int size1;
	cin >> size1;

	int input1[size1];
	for (int i = 0; i < size1; i++){
		cin >> input1[i];
	}

	int size2;
	cin >> size2;

	int input2[size2];
	for (int i = 0; i < size2; i++){
		cin >> input2[i];
	}

	int output[100];

	for (int i = 0; i < 100; i++){
		output[i] = 0;
	}

	sumOfTwoArrays(input1, size1, input2, size2, output);

	for (int i = 0; i < 10; i++){
		cout << output[i] << " ";
	}
	cout << endl;

	return 0;
}