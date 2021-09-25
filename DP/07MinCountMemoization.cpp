#include <iostream>
#include <cmath>
#include <climits>
using namespace std;

int helper(int n, int *ans){
    if (n == 0){
        return 0;
    }
    
    if (ans[n] != -1){
        return ans[n];
    }
    
    int Mnum = INT_MAX;
    int l = pow(n, 0.5);
	for (int i = 1; i <= l; i++){
        int num = pow(i, 2);
        int smallAns;
        if (ans[n - num] != -1){
            smallAns = ans[n - num] + 1;
        }
        else{
            smallAns = helper(n - num, ans);
            smallAns += 1;
        }
        
        if(smallAns < Mnum){
            Mnum = smallAns;
        }
    }
    
    ans[n] = Mnum;
    
    return Mnum;
}

int minCount(int n)
{
	//Write your code here
    int *ans = new int[n + 1];
    for (int i = 0; i < n + 1; i++){
        ans[i] = -1;
    }
    
    return helper(n, ans);
}

int main()
{
	int n;
	cin >> n;
	cout << minCount(n);
}
