#include <iostream>
#define mod 1000000007
using namespace std;

int balancedBTs(int n) {
    int *dp = new int[n + 1];

    dp[0] = dp[1] = 1;
    for(int i = 2; i <= n; i++) {
        long temp = ((long)dp[i - 1] * ((2 * (long)dp [i - 2])%mod + (long)dp[i - 1])%mod) % mod;
        dp[i] = temp;
    }
    return dp[n];
}

int main() {
    int n;
    cin >> n;
    cout << balancedBTs(n) << endl;
}