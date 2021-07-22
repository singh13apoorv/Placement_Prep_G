#include <bits/stdc++.h>
using namespace std;

bool isValidSubsequence(vector<int> array, vector<int> sequence){
	int i = 0;
	int j = 0;
	int idx = INT_MIN;

	while (i < array.size()){
		if (array[i] == sequence[j] && idx < i){
			idx = i;
			j++;
		}
		i++;
		if (j == sequence.size()){
			return true;
		}
	}
	return false;
}

int main(){
	vector<int> array;
	vector<int> sequence;

	array.push_back(1);
	array.push_back(2);
	array.push_back(3);
	array.push_back(25);
	array.push_back(4);
	array.push_back(-1);
	array.push_back(8);
	array.push_back(10);

	sequence.push_back(1);
	sequence.push_back(3);
	sequence.push_back(4);
	sequence.push_back(2);

	cout << isValidSubsequence(array, sequence) << endl;

	return 0;
}