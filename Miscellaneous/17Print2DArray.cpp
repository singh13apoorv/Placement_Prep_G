#include <bits/stdc++.h>
using namespace std;

void print2DArray(int **input, int row, int col) {
    for (int i = 0; i < row; i++){
        int k = row - i;
        while (k > 0){
            for (int j = 0; j < col; j++){
                cout << input[i][j] << " ";
            }
            cout << endl;
            k--;
        }
    }
}

int main() {
    int row, col;
    cin >> row >> col;

    int **input = new int*[row];
    for(int i = 0; i < row; i++) {
        input[i] = new int[col];
        for(int j = 0; j < col; j++) {
            cin >> input[i][j];
        }
    }
    print2DArray(input, row, col);
}