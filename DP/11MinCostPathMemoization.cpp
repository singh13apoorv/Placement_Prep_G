#include <bits/stdc++.h>
using namespace std;

int helper(int **input, int m, int n, int i, int j, int **output){
    if (i == m - 1 && j == n - 1){
        return input[i][j];
    }

    if (i >= m || j >= n){
        return INT_MAX;
    }

    if (output[i][j] != -1){
        return output[i][j];
    }

    int x = helper(input, m, n, i + 1, j, output);
    int y = helper(input, m, n, i + 1, j + 1, output);
    int z = helper(input, m, n, i, j + 1, output);

    int ans = input[i][j] + min(x, min(y, z));
    output[i][j] = ans;

    return ans;
}

int minCostPath(int **input, int m, int n){
    int **output;
    output = new int*[n];
    for (int i = 0; i < n; i++){
        output[i] = new int[m];
    }

    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            output[i][j] = -1;
        }
    }

    return helper(input, m, n, 0, 0, output);
}

int main(){
    int **arr, n, m;
	cin >> n >> m;
	arr = new int *[n];
	for (int i = 0; i < n; i++)
	{
		arr[i] = new int[m];
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> arr[i][j];
		}
	}
	cout << minCostPath(arr, n, m) << endl;
}