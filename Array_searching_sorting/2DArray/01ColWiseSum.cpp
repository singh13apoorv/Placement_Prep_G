#include <bits/stdc++.h>
using namespace std;

int main(){
	int row;
	int col;
	cin >> row >> col;
	int mat[row][col];

	for (int i = 0; i < row; i++){
		for (int j = 0; j < col; j++){
			cin >> mat[i][j];
		}
	}

	for (int j = 0; j < col; j++){
		int colSum = 0;
		for (int i = 0; i < row; i++){
			colSum += mat[i][j];
		}
		cout << colSum << " ";
	}
	cout << endl;

	return 0;
}