#include <bits/stdc++.h>
using namespace std;

void findLargest(int **input, int row, int col){
	int row_idx = 0;
	int col_idx = 0;

	int row_max = INT_MIN;
	int col_max = INT_MIN;
	int col_sum;
	int row_sum;

	for (int i = 0; i < row; i++){
		int row_sum = 0;
		for (int j = 0; j < col; j++){
			row_sum += input[i][j]; 
		}
		if (row_sum > row_max){
			row_idx = i;
			row_max = row_sum;
		}
        else if (row_sum == row_max){
            continue;
        }
	}

	for (int i = 0; i < col; i++){
		int col_sum = 0;
		for (int j = 0; j < row; j++){
			col_sum += input[j][i]; 
		}
		if (col_sum > col_max){
			col_idx = i;
			col_max = col_sum;
		}
        else if (col_sum == col_max){
            continue;
        }
	}

	if (row_max >= col_max){
		cout << "row " << row_idx << " " << row_max << endl;
	}
	else if (col_max > row_max){
		cout << "column " << col_idx << " " << col_max << endl;
	}
	else if (row_max == 0 && col_max == 0){
		cout << "row " << 0 << " " << INT_MIN << endl;
	}
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int row, col;
		cin >> row >> col;

		int **input = new int *[row];
		for (int i = 0; i < row; i++)
		{
			input[i] = new int[col];
			for (int j = 0; j < col; j++)
			{
				cin >> input[i][j];
			}
		}

		findLargest(input, row, col);
	}
}