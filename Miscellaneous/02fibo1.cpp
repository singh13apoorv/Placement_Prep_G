#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;

    int xi = 0;
    int xj = 1;
    int xf;

    for (int i = 2; i <= n; i++){
        xf = xi + xj;
        xi = xj;
        xj = xf;
    }
    cout << xf << endl;

    return 0;
}