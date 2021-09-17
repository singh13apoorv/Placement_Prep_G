#include <iostream>
#include <climits>
using namespace std;

int stepToOneDP(int n){
    int *ans = new int[n + 1];
    ans[1] = 0;

    for (int i = 2; i <= n; i++){
        int temp1 = ans[i - 1];
        int temp2 = INT_MAX;
        int temp3 = INT_MAX;

        if (i % 2 == 0){
            temp2 = ans[i / 2];
        }
        if (i % 3 == 0){
            temp3 = ans[i / 3];
        }

        int out = 1 + min(temp1, min(temp2, temp3));
        ans[i] = out;
    }

    return ans[n];
}

int main(){
    int n;
    cout << "Enter a number: ";
    cin >> n;

    cout << stepToOneDP(n) << endl;

    return 0;
}