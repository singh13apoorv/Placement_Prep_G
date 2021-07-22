#include <bits/stdc++.h>
using namespace std;

void wavePrint(int **input, int rows, int cols){
    for (int i = 0; i < cols; i++){
        if (i % 2 == 0){
            for (int j = 0; j < rows; j++){
                cout << input[j][i] << endl;
            }
        }
        else {
            for (int j = rows - 1; j >= 0; j--){
                cout << input[j][i] << endl; 
            }
        }
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

		wavePrint(input, row, col);
	}
}