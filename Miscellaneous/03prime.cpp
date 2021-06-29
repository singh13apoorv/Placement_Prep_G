#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;

    for (int i = 2; i <= n; i++){
        bool b = false;
        if (i == 2){
            cout << 2 << endl;
            continue;
        }

        for (int j = 2; j < i; j++){
            if (i % j == 0){
                b = true;
                break;
            }
        }

        if (b == true){
            continue;
        }
        else {
            cout << i << endl;
        }
    }

    return 0;
}