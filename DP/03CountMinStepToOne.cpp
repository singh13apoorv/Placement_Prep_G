#include <iostream>
#include <climits>
using namespace std;

int stepToOne(int n){
    if (n == 1){
        return 0;
    }

    int way1 = stepToOne(n - 1);
    int way2 = INT_MAX;
    int way3 = INT_MAX;

    if (n % 2 == 0){
        way2 = stepToOne(n / 2);
    }
    if (n % 3 == 0){
        way3 = stepToOne(n / 3);
    }

    int ans = 1 + min(way1, min(way2, way3));

    return ans;
}

int main(){
    int n;
    cout << "Enter a number to count min step to one: ";
    cin >> n;

    cout << stepToOne(n) << endl;

    return 0;
}