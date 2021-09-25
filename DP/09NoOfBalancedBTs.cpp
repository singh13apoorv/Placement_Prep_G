#include <iostream>
#define mod 1000000007
using namespace std;

int balancedBTs(int n) {
    // Write your code here
    if (n == 0){
        return 1;
    }
    if (n == 1){
        return 1;
    }
    
    long smallAns1 = balancedBTs(n - 1);
    long smallAns2 = balancedBTs(n - 2);
    
    int ans= (smallAns1 * ((2 * smallAns2) % mod + smallAns1 % mod)) % mod;
    return ans;
}

int main() {
    int n;
    cin >> n;
    cout << balancedBTs(n) << endl;
}