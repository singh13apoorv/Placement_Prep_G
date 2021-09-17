#include <iostream>
using namespace std;

int fib_helper(int n, int *ans){
    if (n <= 1){
        return n;
    }

    if (ans[n] != -1){
        return ans[n];
    }

    int smallAns_a = fib_helper(n - 1, ans);
    int smallAns_b = fib_helper(n - 2, ans);

    ans[n] = smallAns_a + smallAns_b;

    return ans[n];
}

int fib(int n){
    int *ans = new int[n + 1];
    for (int i = 0; i < n + 1; i++){
        ans[i] = -1;
    }
    int output = fib_helper(n, ans);

    return output;
}

int main(){
    int n;
    cout << "Enter the number for which you want to find the fibonacci: ";
    cin >> n;

    cout << fib(n) << endl;

    return 0;
}